#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(string a, string b) {
    return a+b<b+a;
}

string str[10010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        cin >> str[i];
    sort(str, str+n, cmp);
    string s;
    for(int i=0; i<n; i++)
        s += str[i];
    while(s.length()!=0 && s[0]=='0') //È¥µôÇ°µ¼Áã
        s.erase(s.begin());
    if(s.length()==0) cout <<0;
    cout << s;
    return 0;
}
