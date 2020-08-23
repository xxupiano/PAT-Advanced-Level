#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long ag,as,ak,bg,bs,bk,cg,cs,ck;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &ag,&as,&ak,&bg,&bs,&bk);
    long long A = 493*ag+29*as+ak;
    long long B = 493*bg+29*bs+bk;
    long C = A+B;
    cg = C/493;
    C -= cg*493;
    cs = C/29;
    ck = C-cs*29;
    printf("%lld.%lld.%lld", cg, cs, ck);
    return 0;
}
