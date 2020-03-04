#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, maxheight=0;
vector<vector<int>> v;
set<int> s;
vector<int> temp;
bool vis[10010];

void dfs(int node, int height) {
    if(height>maxheight) {
        maxheight = height;
        temp.clear();
        temp.push_back(node);
    } else if(height==maxheight) {
        temp.push_back(node);
    }
    vis[node] = true;
    for(int i=0; i<v[node].size(); i++) {
        if(vis[v[node][i]]==false) {
            dfs(v[node][i], height+1);
        }
    }
}

int main() {
    scanf("%d", &n);
    int a,b;
    v.resize(n+1);
    for(int i=1; i<=n-1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0, rand=0;
    for(int i=1; i<=n; i++) {
        if(vis[i]==false) {
            cnt++;
            dfs(i,1);
            if(i==1) {
                if(temp.size()!=0) rand=temp[0];
                for(int j=0; j<temp.size(); j++)
                    s.insert(temp[j]);
            }
        }
    }
    if(cnt>=2) printf("Error: %d components", cnt);
    else {
        temp.clear();
        maxheight=0;
        fill(vis, vis+10010, false);
        dfs(rand, 1);
        for(int i=0; i<temp.size(); i++)
            s.insert(temp[i]);
        for(auto it = s.begin(); it!=s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
