#include <iostream>
#include <cstdio>
using namespace std;

int cur=0, sum=0;

int main()
{
    int n;
    scanf("%d", &n);
    int t;
    for(int i=1; i<=n; i++) {
        scanf("%d", &t);
        if(t>cur) {
            sum += (t-cur)*6 + 5;
            cur=t;
        }
        else {
            sum += (cur-t)*4 + 5;
            cur=t;
        }
    }
    printf("%d", sum);
    return 0;
}
