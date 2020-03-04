#include <iostream>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, cnt, k, a[210][210]={0};
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int t1,t2;
        scanf("%d %d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;
    }
    scanf("%d", &cnt);
    while(cnt--) {
        scanf("%d", &k);
        vector<int> v(k);
        set<int> s;
        int flag=1;
        for(int i=0; i<k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size()!=n || k-1!=n || v[0]!=v[k-1])
            printf("NO\n");
        else {
            for(int i=0; i<k-1; i++)
                if(a[v[i]][v[i+1]]==0) {
                    flag=0;
                    break;
                }
            printf("%s", flag?"YES\n":"NO\n");

        }
    }
    return 0;
}
