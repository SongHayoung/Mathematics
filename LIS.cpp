#include <stdio.h>
#include <vector>
using namespace std;
#define INF -987654321
#define MAXLEN 10
vector<int> vt;
int main(int argc, char** argv)
{
    int arr[MAXLEN] = {10, 20, 40, 25, 20, 50, 30, 70, 85};
    vt.push_back(-INF);
    for(int i=0; i<MAXLEN; i++){
        if(vt.back()<arr[i])
            vt.push_back(arr[i]);
        else{
            auto it = lower_bound(vt.begin(),vt.end(),arr[i]);
            *it = arr[i];
        }
    }
    printf("LIS : %d\n",vt.size());
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
