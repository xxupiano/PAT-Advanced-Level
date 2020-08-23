#include <iostream>
#include <stack>
#include <cstdio>
#define lowbit(i) ((i)&(-i))
const int maxn = 100010;
using namespace std;

int c[maxn];
stack<int> s;

void update(int x, int v) {
    for(int i=x; i<maxn; i+=lowbit(i))
        c[i] += v;
}

int getsum(int x) {
    int sum=0;
    for(int i=x; i>=1; i-=lowbit(i))
        sum += c[i];
    return sum;
}

void PeekMedian() {
    int l=1, r=maxn;
    int mid, k=(s.size()+1)/2;
    while(l<r) {
        mid = (l+r)/2;
        if(getsum(mid)>=k)
            r=mid;
        else l=mid+1;
    }
    printf("%d\n", l);
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i=0; i<n; i++) {
        scanf("%s", str);
        if(str[1]=='u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1]=='o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n",s.top());
                s.pop();
            }else printf("Invalid\n");
        } else {
            if(!s.empty())
                PeekMedian();
            else printf("Invalid\n");
        }
    }
    return 0;
}
