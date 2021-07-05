#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
long long* solution(long long numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int arr[50];
    int k;
    long long* answer = (long long*)malloc(numbers_len*sizeof(long long));
    //printf("%lld",numbers[0]);
    int i,m,j;
    int result1,result,testing;
    int sum=1;
    int max;
    long long testnum;
    for(m=0;m<numbers_len;m++){
        sum=1;
        testnum=numbers[m];
        printf("%lld 검사시작 -\n",testnum);
        printf("2진법 계산 :");
        for (int x = 7; x >= 0; --x) {
            int result = testnum >> x & 1;
            printf(" %d", result);
        }
        printf("\n");
        
        for (i = 0; i<=50; i++) { 
                if(1 != (testnum >> i & 1))
                    break;
        }
        printf("i :%d,",i);
        
        for(j=1;j<i;j++){
            sum*=2;
        }
        printf("sum : %d \n",sum);
        answer[m]=testnum+sum;  
        
        printf("검사결과 answer[%d]:%lld \n",m,answer[m]);
        printf("-----------------------------\n");
    }
    
    return answer;
}