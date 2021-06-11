#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int solution(int n) {
    int answer = 0;
    char* str=(char*)malloc(sizeof(char)*10);
    sprintf(str,"%d",n);
    int i;
    
    for(i=0;(int)str[i]>47 && (int)str[i]<59;i++)
    {
        answer+=( (int)str[i]-48 );
    }
    printf("%d",(int)str[0]-48);
    
    return answer;
}