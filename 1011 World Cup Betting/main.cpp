#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int maxn=-1;
    int mi;
    double sum=1;
    double score[4];
    int x = 3;
    while(x--) {
        maxn=-1;
        for(int i=1; i<=3; i++) {
            cin >> score[i];
            if(score[i]>=maxn) {maxn = score[i];mi=i;}
        }
        if(mi==1) printf("W ");
        else if(mi==2) printf("T ");
        else if(mi==3) printf("L ");
        sum *= score[mi];
    }
    sum = (sum*0.65-1)*2;

    printf("%.2f", sum);
    return 0;
}
