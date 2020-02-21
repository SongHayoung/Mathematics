#include <stdio.h>
using namespace std;

int fastSum(int n){
    if(n==1) return 1;
    if(n&1==1) return fastSum(n-1) + n;
    return (fastSum(n>>1)<<1) + (n>>1)*(n>>1);
}
int fastPow(int n, int p){
    if(p==1)    return n;
    if(p&1==1)  return fastPow(n,p-1) * n;
    int half = fastPow(n,p>>1);
    return half*half;
}
int main(int argc, char** argv)
{
    int NUM = 10;
    int N = 2, P = 10;
    printf("fastSum %d = %d\n",NUM,fastSum(NUM));
    printf("fastPow %d^%d =  %d\n",N,P,fastPow(N,P));
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
