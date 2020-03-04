#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n, k; //stu, course
map<string, set<int>> mmap;

int main()
{
    scanf("%d%d", &n, &k);
    int index, temp;
    for(int i=0; i<k; i++) {
        scanf("%d%d", &index, &temp);
        string name;
        for(int j=0; j<temp; j++) {
            cin >> name;
            mmap[name].insert(index);
        }
    }

    string name;
    for(int i=1; i<=n; i++) {
        cin >> name;
        cout << name;
        printf(" %d", mmap[name].size());
        for(auto it=mmap[name].begin(); it!=mmap[name].end();it++) {
            printf(" %d", *it);
        }
        if(i!=n) printf("\n");
    }
    return 0;
}
