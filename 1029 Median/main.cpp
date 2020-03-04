#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, temp;
vector<int> a;

int main() {
    scanf("%d", &n);
    a.push_back(0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &temp);
        a.push_back(temp);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++) {
        scanf("%d", &temp);
        a.push_back(temp);
    }
    sort(a.begin()+1, a.end());
    cout << a[(n+m+1)/2];
}
