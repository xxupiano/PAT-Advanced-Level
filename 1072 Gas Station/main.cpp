#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
const int inf = 99999999;
int n,m,k,ds, station;
//房子数，location数，路条数，最大服务范围
int e[1020][1020], dis[1020];
bool vis[1020] = {false};

int main() {
    fill(e[0], e[0]+1020*1020, inf);
    fill(dis, dis+1020, inf);
    scanf("%d%d%d%d", &n,&m,&k,&ds);
    for(int i=0; i<k; i++) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a,b;
        if(s[0]=='G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a=stoi(s);
        }
        if(t[0]=='G') {
            t = t.substr(1);
            b = n+stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b]=e[b][a]=tempdis;
    }

    int ansid=-1;
    double ansdis=-1, ansaver=inf;
    for(int index=n+1; )
}
