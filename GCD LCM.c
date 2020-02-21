#include <stdio.h>
int gcd(int p, int q){
    if(q==0) return p;
    return gcd(q, p%q);
}
int lcm(int p, int q){
    return p * q / gcd(p,q);
}
int main(int argc, char** argv)
{
    int A, B;
    setbuf(stdout, NULL);
    scanf("%d %d",&A,&B);
    printf("%d %d\n",gcd(A,B),lcm(A,B));
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
