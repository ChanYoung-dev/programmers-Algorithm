#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    char* str=s;
    char* answer = (char*)malloc(strlen(s));
    printf("%s",str);
    char *temp = strtok(str," "); //공백을 기준으로 문자열 자르기
    int i;
    int h=0;
    while (temp != NULL) { //널이 아닐때까지 반복
        printf("%s\n",temp); // 출력
        //짝수이고 소문자일경우 -> 대문자 치환작업
        for(i=0;temp[i]!=NULL;i++,h++){
        
            if(i%2==0 && temp[i]>96 && temp[i]<123){
            
                printf("%c ->",temp[i]);
            
                answer[h]=temp[i]-32;
            
                printf("%c \n",answer[h]);
                
        
            }
            else if(i%2==1 && temp[i]>64 && temp[i]<91){
            
                printf("%c ->",temp[i]);
            
                answer[h]=temp[i]+32;
            
                printf("%c \n",answer[h]);
                
        
            }
            else
                answer[h]=temp[i];
        }
        answer[h]=' ';
        printf("answer : %s \n",answer);
        h++;
        temp = strtok(NULL, " ");	//널문자를 기준으로 다시 자르기
    }
    answer[--h]=NULL;
    
    return answer;
}