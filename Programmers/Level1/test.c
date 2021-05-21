#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i=0;
    long long Max=0;
    long long checkMax=1;
    //12345-> 10000 최대자릿수 값
    while(n/checkMax>=10)
        checkMax*=10;
    Max=checkMax;
    //10000은 자릿수가 5이다
    for(i=0;checkMax>=1;i++)
        checkMax/=10;
    // 자릿수값 대입할 배열
    int* answer = (int*)malloc(i*sizeof(int));
    // 배열에 자릿수 값 대입
    while(i>0){
        //자릿수 대입
        answer[--i]=n/Max;
        //최대값 제거 12345-10000
        n-=answer[i]*Max;
        //그다음 자릿수를 위해 나누기 10000/10 = 1000
        Max/=10;
    }
    return answer;
}