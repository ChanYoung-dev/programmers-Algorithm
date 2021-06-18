#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(prices_len*sizeof(int));
    
    int i,j;
    for(i=0;i<prices_len-1;i++){
        for(j=1;i+j<prices_len;j++){
            if(prices[i]>prices[i+j]){
                answer[i]=j;
                break;
            }
            answer[i]=j;
        }
    }
    answer[i]=0;
    return answer;
}