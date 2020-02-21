#include <stdio.h>
#include <vector>
using namespace std;
vector<int> s, t, r, q;
int i;
void INIT_EEC_Table(int A, int B){
    s.clear(); t.clear(); r.clear(); q.clear();
    s.push_back(1);
    s.push_back(0);
    t.push_back(0);
    t.push_back(1);
    r.push_back(A);
    r.push_back(B);
    q.push_back(0);
    q.push_back(A/B);
}
void EEC(int A,int B){
    INIT_EEC_Table(A,B);
    i = 1;
    while(r[i-1]%r[i]){
        r.push_back(r[i-1] - r[i] * q[i]);
        s.push_back(s[i-1] - s[i]*q[i]);
        t.push_back(t[i-1] - t[i]*q[i]);
        ++i;
        q.push_back(r[i-1]/r[i]);
    }
}
int main(int argc, char** argv)
{
    int A, B;
    scanf("%d %d",&A,&B);
    EEC(A,B);
    printf("#%d %d %d\n",s[i],t[i]);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
/*
 *      I               S                            T                            R                     Q
 *      0               1                            0                            A                     0
 *      1               0                            1                            B                    A/B      ///Initialize
 *      2      s[i-2] - s[i-1]*q[i-1]       t[i-2] - t[i-1]*q[i-1]       r[i-2] - r[i-1]*q[i-1]   r[i-1]/r[i]   ///Calculate
 *
 */
