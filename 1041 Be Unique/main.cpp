#include <iostream>
#include <cstdio>
using namespace std;

int a[100000+5]={0}, m[100000+10];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }
    for(int i=0; i<n; i++) {
        if(m[a[i]]==1) {
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}
