#include <stdio.h>
#include <memory.h>
#define MAXNUM 1000000

bool is_Prime[500001];  //(MAXNUM/2) + 1

int main(int argc, char** argv){
    register int i;
    memset(is_Prime,true,sizeof(is_Prime));
    is_Prime[0] = false;
    for(int i=3; i*i<=MAXNUM;i+=2){
        if(is_Prime[i>>1]){
            for(int j = i*i; j<=MAXNUM; j += (i<<1))
                is_Prime[j>>1] = false;
        }
    }
    printf("Prime : 2\n");
    for(i=3;i<=MAXNUM; i+=2){
        if(is_Prime[i>>1])
            printf("Prime : %d\n",i);
    }
}
