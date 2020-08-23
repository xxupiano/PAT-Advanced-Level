#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct mooncake {
    float mount, price, unit;
};

int cmp(mooncake a, mooncake b) {
    return a.unit>b.unit;
}

int main()
{
    int n, need;
    scanf("%d %d", &n, &need);
    vector<mooncake> a(n);
    for(int i=0; i<n; i++)
        scanf("%f", &a[i].mount);
    for(int i=0; i<n; i++) {
        scanf("%f", &a[i].price);
        a[i].unit = a[i].price / a[i].mount;
    }
    sort(a.begin(), a.end(), cmp);
    float result = 0.0;
    for(int i=0; i<n; i++) {
        if(a[i].mount<=need) {
            result += a[i].price;
        } else {
            result += a[i].unit*need;
            break;
        }
        need -= a[i].mount;
    }
    printf("%.2f", result);
    return 0;
}
