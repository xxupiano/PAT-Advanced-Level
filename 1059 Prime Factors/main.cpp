/*先建⽴立个500000以内的素数表，
然后从2开始⼀一直判断是否为它的素数，
如果是就将a=a/i继续 判断i是否为a的素数，
判断完成后输出这个素数因子和个数，
用state判断是否输入过因子，
输入过就 要再前面输出“*”
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> prime(500000, 1);

int main()
{
    for(int i=2; i*i<500000; i++) {
        for(int j=2; j*i<500000; j++)
            prime[j*i]=0;
    }
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if(a==1) printf("1");
    bool state=false;
    for(int i=2; a>=2; i++) {
        int cnt=0, flag=0;
        while(prime[i]==1 && a%i==0) {
            cnt++;
            a /= i;
            flag=1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt>=2)
            printf("^%d", cnt);
    }
    return 0;
}
