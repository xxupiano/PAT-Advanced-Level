#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[105];
vector<int> book(105);
int maxdepth = -1;

void dfs(int index, int depth) {
    if(v[index].size()==0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    for(int i=0; i<v[index].size(); i++) {
        dfs(v[index][i], depth+1);
    }
}

int main()
{
    int n,m,k,node,c;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &node, &k);
        for(int j=0; j<k; j++){
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 1);
    printf("%d", book[1]);
    for(int i=2; i<=maxdepth; i++) {
        printf(" %d", book[i]);
    }
    return 0;
}
