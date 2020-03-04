#include <iostream>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

int k;
vector<int> num;
set<int> ans;

int main()
{
    scanf("%d", &k);
    int n;
    while(k--){
        scanf("%d", &n);
        while(n) {
            num.push_back(n%10);
            n /= 10;
        }
        int sum=0;
        for(int i=0; i<num.size(); i++) {
            sum += num[i];
        }
        ans.insert(sum);
        num.clear();
    }
    printf("%d\n", ans.size());
    auto it = ans.begin();
    printf("%d", *it);
    for(it++; it!=ans.end(); it++) {
        printf(" %d", *it);
    }
    return 0;
}
