#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,c1,c2;
int e[510][510], vis[510] = {0};
const int inf=99999999;
int dis[510], num[510], weight[510], w[510];

int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i=0; i<n; i++) scanf("%d", &weight[i]);
    int a,b,c;
    fill(e[0], e[0]+510*510, inf);
    fill(dis, dis+510, inf);
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b]=e[b][a]=c;
    }
    dis[c1]=0;
    num[c1]=1;
    w[c1]=weight[c1];
    for(int i=0; i<n; i++) {
        int u=-1, minn=inf;
        for(int j=0; j<n; j++) {
            if(vis[j]==0 && dis[j]<minn) {
                minn=dis[j];
                u=j;
            }
        }
        if(u==-1) break;
        vis[u]=1;
        for(int v=0; v<n; v++) {
            if(vis[v]==0 && e[u][v]!=inf) {
                if(dis[v]>dis[u]+e[u][v]) {
                    dis[v]=dis[u]+e[u][v];
                    num[v]=num[u];
                    w[v]=w[u]+weight[v];
                }
                else if(dis[v]==dis[u]+e[u][v]) {
                    num[v]=num[u]+num[v];
                    if(w[u]+weight[v]>w[v])
                        w[v]=w[u]+weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}

