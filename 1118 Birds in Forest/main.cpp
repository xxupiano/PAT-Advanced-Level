#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
const int maxn = 10010;

int fa[maxn]={0}, cnt[maxn]={0};

int getf(int x) {
    if(fa[x]==x) return x;
    else return fa[x] = getf(fa[x]);
}

void mergef(int a, int b) {
    int t1 = getf(a);
    int t2 = getf(b);
    if(t1!=t2) fa[t2] = t1;
}

bool exist[maxn];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=maxn; i++)
        fa[i] = i;
    int id, temp;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &k, &id);
        exist[id] = true;
        for(int j=0; j<k-1; j++) {
            scanf("%d", &temp);
            mergef(id, temp);
            exist[temp] = true;
        }
    }
    for(int i=1; i<=maxn; i++) {
        if(exist[i] == true) {
            int root = getf(i);
            cnt[root]++;
        }
    }
    int numTrees = 0, numBirds = 0;
    for(int i=1; i<=maxn; i++) {
        if(exist[i]==true && cnt[i]!=0) {
            numTrees++;
            numBirds += cnt[i];
        }
    }
    printf("%d %d\n", numTrees, numBirds);
    scanf("%d", &m);
    int ida, idb;
    while(m--) {
        scanf("%d%d", &ida, &idb);
        printf("%s\n", getf(ida)==getf(idb)?"Yes":"No");
    }
}
