#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* phone_number) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    //+1을 한 이유는 끝에 널문자 \0이 들어가기 때문이다.
    char* answer = (char*)malloc(strlen(phone_number)+1);
    int i;
    int j=0;
    //printf("%d",strlen(phone_number));
    for(i=0;i<strlen(phone_number);i++){
        printf("%c \n",phone_number[i]);
        if(i>=strlen(phone_number)-4)
        {
            printf("check : %c \n",phone_number[i]);
            answer[i]=phone_number[i];
        }
        else
            answer[i]='*';
        
    }
    answer[i]='\0';
    return answer;
}