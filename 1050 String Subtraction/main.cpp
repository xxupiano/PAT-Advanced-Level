#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s1, s2;
int main() {
    getline(cin, s1);
    getline(cin, s2);
    int lens1 = s1.length();
    int lens2 = s2.length();
    bool flag[256] = {false};
    for(int i=0; i<lens2; i++)
        flag[s2[i]] = true;
    for(int i=0; i<lens1; i++) {
        if(!flag[s1[i]])
            printf("%c", s1[i]);
    }
    return 0;
}
