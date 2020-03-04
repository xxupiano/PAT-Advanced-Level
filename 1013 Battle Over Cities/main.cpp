#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> v(1010, vector<int>(1010));
vector<int> vis(1010);
int n, m, k;

void dfs(int node) {
    vis[node] = 1;
    for(int i=1; i<=n; i++) {
        if(vis[i]==0 && v[node][i]==1) dfs(i);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int a,b;
    while(m--) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    while(k--) {
        fill(vis.begin(), vis.end(), 0);
        scanf("%d", &a);
        int cnt = 0;
        vis[a] = 1;
        for(int j=1; j<=n; j++) {
            if(vis[j]==0) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt-1);
    }
}
