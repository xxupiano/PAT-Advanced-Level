#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

string s;
int ans = 1;
int dp[1010][1010];
//dp[i][j]表示s[i]到s[j]所表示的字串是否是回文字串。

int main()
{
    getline(cin, s);
    int len = s.length();
    fill(dp[0], dp[0]+1010*1010, 0);
    for(int i=0; i<len; i++) {
        dp[i][i]=1;
        if(i<len-1 && s[i]==s[i+1]) {
            dp[i][i+1]=1;
            ans = 2;
        }
    }

    for(int L=3; L<=len; L++) {
        for(int i=0; i+L-1<len; i++) {
            int j = i+L-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1) {
                dp[i][j]=1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
