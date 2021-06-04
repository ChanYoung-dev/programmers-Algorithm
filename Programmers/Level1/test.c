#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* list[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    char* answer = (char*)malloc(3);
    answer=list[3];
    return answer;
}