#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> book(201), a(10001), dp(10001);

int main()
{
    int n,m,x,l, num=0, maxn=0;
    scanf("%d %d", &n, &m);
    fill(dp.begin(), dp.end(), 1);
    for(int i=1; i<=m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i=0; i<l; i++) {
        scanf("%d", &x);
        if(book[x]>=1)
            a[num++] = book[x];
    }
    for(int i=0; i<num; i++) {
        for(int j=0; j<i; j++) {
            if(a[i]>=a[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
