#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int e[510][510], vis[510], cost[510][510], dis[510];
const int inf = 99999999;
vector<int> pre[510];
vector<int> path, temppath;
int mincost = inf;

void dfs(int v) {
    temppath.push_back(v);
    if(v==s) {
        int tempcost=0;
        for(int i=temppath.size()-1; i>0; i--) {
            int id=temppath[i], nextid=temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost<mincost) {
            mincost=tempcost;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    for(int i=0; i<pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s,&d);
    fill(e[0], e[0]+510*510, inf);
    fill(vis, vis+510, 0);
    fill(dis, dis+510, inf);
    int a,b;
    while(m--) {
        scanf("%d%d",&a,&b);
        scanf("%d",&e[a][b]);
        e[b][a]=e[a][b];
        scanf("%d",&cost[a][b]);
        cost[b][a]=cost[a][b];
    }
    pre[s].push_back(s);
    for(int i=0; i<n; i++) {
        dis[i] = e[s][i];
    }
    dis[s]=0;
    for(int i=0; i<n-1; i++) {
        int u = -1, minn = inf;
        for(int j=0; j<n; j++) {
            if(vis[j]==0&&dis[j]<minn) {
                minn=dis[j];
                u=j;
            }
        }
        if(u==-1) break;
        vis[u] = 1;
        for(int v=0; v<n; v++) {
            if(e[u][v]!=inf && vis[v]==0) {
                if(dis[v]>dis[u]+e[u][v]) {
                    dis[v]=dis[u]+e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v]=dis[u]+e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(d);
    for(int i=path.size()-1; i>=0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", dis[d], mincost);
}
