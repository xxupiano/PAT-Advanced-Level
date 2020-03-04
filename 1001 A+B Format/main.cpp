#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a,b;
vector<char> v;

int main()
{
    cin>>a>>b;
    int sum = a+b;
    if(sum<0) {
        printf("-");
        sum *= -1;
    }
    string s = to_string(sum);
    reverse(s.begin(), s.end());
    int cnt=0;
    for(int i=0; i<s.length(); i++) {
        if(cnt==3) {v.push_back(','); cnt=0;}
        cnt++;
        v.push_back(s[i]);
    }
    for(int i=v.size()-1; i>=0; i--) {
        cout << v[i];
    }
    return 0;
}
