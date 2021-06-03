include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SWAP(a,b) {int c = a; a=b; b=c;} 
int* solution(int numbers[], size_t numbers_len) {
    int* answer = (int*)malloc(sizeof(int)*200);
    int cnt=0;
    for (int i=0; i<numbers_len-1; i++){
        for (int j=i+1; j<numbers_len; j++){
            int tmp = numbers[i]+numbers[j];
            int flag = 1;
	    //같은 숫자 체크
            for (int k=0; k<cnt; k++){
                if (answer[k]==tmp)
                    flag = 0;
            }
            if (flag ==1)
                answer[cnt++]=tmp;
        }
    }
//버블정렬
    for (int i=0; i<cnt; i++){
        for (int j=0; j<cnt-1-i; j++){
            if (answer[j]>answer[j+1])
                SWAP(answer[j],answer[j+1]);
        }
    }
    return answer;
}