#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int k, n;
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        scanf("%d", &n);
        vector<int> v(n);
        bool result = true;
        for(int j=0; j<n; j++) {
            scanf("%d", &v[j]);
            if(!result) continue;
            for(int t=0; t<j; t++) {
                if(v[j]==v[t]||abs(v[j]-v[t])==abs(j-t)) {
                    result = false;
                    break;
                }
            }
        }
        cout << ((result==true)? "YES\n" : "NO\n");
    }
    return 0;
}
