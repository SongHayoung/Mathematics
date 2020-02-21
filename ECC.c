#include <stdio.h>
struct Solution { int gcd, x, y; };
int s[10000], t[10000], r[10000], q[10000];
int i;
void INIT_EEC_Table(int A, int B){
    s[1] = t[0] = q[0] = 0;
    s[0] = t[1] = 1;
    r[0] = A, r[1] = B;
    q[1] = A/B;
}
void Show_Table(){
    printf("I\t\tS\t\tT\t\tR\t\tQ\n");
    for(int j = 0; j<=i; j++)
        printf("%d : \t%d\t\t%d\t\t%d\t\t%d\n",j,s[j],t[j],r[j],q[j]);
}
void EEC(int A,int B){
    INIT_EEC_Table(A,B);
    i = 1;
    while(r[i-1]%r[i]){
        r[i+1] = (r[i-1] - r[i] * q[i]);
        s[i+1] = (s[i-1] - s[i]*q[i]);
        t[i+1] = (t[i-1] - t[i]*q[i]);
        ++i;
        q[i] = (r[i-1]/r[i]);
    }
    Show_Table(); 
}
Solution extendedEuclid(int a, int b) {
	int q = a / b, r = a % b;
	if (r == 0) return Solution{ b, 0, 1 };
	Solution s = extendedEuclid(b, r);
	return Solution{ s.gcd, s.y, s.x - q * s.y };
}
int main(int argc, char** argv)
{
    int A, B;
    scanf("%d %d",&A,&B);
    EEC(A,B);
    printf("%d %d\n",s[i],t[i]);
    Solution s = extendedEuclid(A,B);
    printf("%d %d\n",s.x, s.y);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
/*
 *      I               S                            T                            R                     Q
 *      0               1                            0                            A                     0
 *      1               0                            1                            B                    A/B      ///Initialize
 *      2      s[i-2] - s[i-1]*q[i-1]       t[i-2] - t[i-1]*q[i-1]       r[i-2] - r[i-1]*q[i-1]   r[i-1]/r[i]   ///Calculate
 *
 */
