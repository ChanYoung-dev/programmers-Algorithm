/*
끝 비트에서 0이 몇번째자리에서 나오냐가 핵심이다.
끝자리가 11110 :  
-> +1을 할경우   정답
끝자리가 11101 :
-> +1을 할경우 11110 정답
끝자리가       11011
-> +1을 할경우 11100 다른게 3개이므로 오답
-> +2을 할경우 11101 다른게 2개이므로 정답
끝자리가       10111
-> +1을 할경우 11000 다른게 4개이므로 오답
-> +2을 할경우 11001 다른게 3개이므로 오답
-> +4을 할경우 11011 다른게 2개이므로 정답
끝자리가       101111
-> +1을 할경우 110000 다른게 5개이므로 오답
-> +2을 할경우 110001 다른게 4개이므로 오답
-> +4을 할경우 110011 다른게 3개이므로 정답
-> +8을 할경우 110111 다른게 2개이므로 정답
기존값에 1,2,4,8,16 ... 2의제곱근만 더해주면된다.
*/



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
long long* solution(long long numbers[], size_t numbers_len) {
    long long* answer = (long long*)malloc(numbers_len*sizeof(long long));
    int i,m,j;
    long long sum=1;
    for(m=0;m<numbers_len;m++){
        sum=1;
        //0의 자리가 i번째에서 뜨는가?
        for (i = 0; i<=50; i++) 
                if(1 != (numbers[m] >> i & 1))
                    break;
        // 기존값 + 2의 (i-j)제곱근
        for(j=1;j<i;j++)
            sum*=2;
        answer[m]=numbers[m]+sum;  
    }
    return answer;
}