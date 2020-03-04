#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string letter[10] = {"zero", "one", "two", "three", "four",
                     "five", "six", "seven", "eight", "nine"};

int main()
{
    string s;
    cin >> s;
    int sum=0;
    for(int i=0; i<s.length(); i++) {
        sum += s[i]-'0';
    }
    string x = to_string(sum);
    cout << letter[x[0]-'0'];
    for(int i=1; i<x.length(); i++) {
        cout << " " << letter[x[i]-'0'];
    }

    return 0;
}
