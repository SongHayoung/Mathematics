#include <stdio.h>

#define MOD 1234567891
#define MAX_N 1000000
#define ll long long
ll FACT[MAX_N+1];
ll REFACT[MAX_N+1];
ll getPOWED(ll N, ll P){
    ll result = 1;
    do{
        if(P&1==1){
            result *= N;
            result %= MOD;
        }
        N *= N;
        N %= MOD;
    }while(P>>=1);
    return result;
}
int main(int argc, char** argv) {
    int N,R,i;
    scanf("%d %d",&N,&R);
    FACT[1] = 1;
    for(i = 2; i<=N; i++)
        FACT[i] = (FACT[i-1]*i)%MOD;
    REFACT[MAX_N] = getPOWED(FACT[MAX_N],MOD-2);
    R = N-R > R ? R : N-R;
    for(i=MAX_N-1; i>=R; i--)
        REFACT[i] = (REFACT[i+1]*(i+1))%MOD;    // (N-1)!^-1 = N!^-1 * N
    printf("%llu\n",i,(((FACT[N] * REFACT[R])%MOD)*REFACT[N-R])%MOD);
    
}
/*
 * 페르마의 소정리    mod가 소수일 경우에만 적용가능하다
 * (a^mod)%mod = (a^1)%mod = a%mod
 * (a^(mod-1))%mod = (a^0)%mod = 1%mod = 1
 * (a^(mod-2))%mod = (a^-1)%mod
 *
 *
 * nCr%mod = n!*((r!*(n-r)!)^-1)%mod
 * ==> n!%mod * ((r!*(n-r)!)^-1)%mod
 *
 * ((r!*(n-r)!)^-1)%mod = ((r!^-1)%mod) * (((n-r)!^-1)%mod)
 * (r!^-1)%mod = r^(mod-2)%mod
 * ((n-r)!^-1)%mod = ((n-r)!^(mod-2))%mod
 *
 * ==> nCr%mod = n! * ((r^(mod-2))%mod * (((n-r)!^(mod-2))%mod))
 *
 * REFACT[N] = (FACT[N]^-1)%mod = (FACT[N]^(mod-2))%mod
 *
 * ==> answer of nCr = FACT[N]*REFACT[R]*REFACT[N-R]%mod
 *
 * function of getPOWED returns (N^P)%MOD
 * Ex) if P is 23 => 10111(2) => N^(16 + 4 + 2 + 1)
 * N^(16 + 4 + 2 + 1) = N^16(8 + 8) * N^4(2 + 2) * N^2(1 + 1) * N*1
 * /
