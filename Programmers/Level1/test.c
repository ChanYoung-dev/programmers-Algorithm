#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* list[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int countday=0;
    //월 계산
    for(int i=1;i<a;i++)
        countday+=day[i-1];
    //일 계산
    countday+=(b-1);
    char* answer = (char*)malloc(3);
    answer=list[(countday%7)];
    
    return answer;
}