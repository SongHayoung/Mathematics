#include <stdio.h>
int main(int argc, char** argv)
{
    int N; 
    long answer;
    char c;
    setbuf(stdout, NULL);
    scanf("%d",&N);
    getchar(); 
    c='0';
    switch (N) {
        case 2:
            while('0'<=c&&c<='9'){
                c = getchar();
            }
            printf("0\n");
            break;
        default:
            answer = 0;
            do{
                answer += c-48;
                c = getchar();
            }while('0'<=c&&c<='9');
            printf("%d\n",answer%(N-1));
            break;
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
/*
 * 공식 : N진법의 수 X를 N-1로 나눈 나머지는 모든 자리의 수를 더한 뒤 N-1로 나눈 나머지이다
 */
