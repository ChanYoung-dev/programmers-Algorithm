#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    
    
    char* su="수";
    char* bak="박";
    
    printf("%d",strlen(su)); //글자는 하나당 3크기 체크
    
    char* answer = (char*)malloc(sizeof(char)*n*3); //n개 * 3(한글자크기)
    strcpy(answer, ""); //answer 초기화
    for(int i=0;i<n;i++){
        if(i%2==0)
            strcat(answer,su);
        else
            strcat(answer,bak);
    }
    return answer;
}