#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    int i=5;
    int sum=0;
    int originalX;
    bool answer = true;
    //최대 자릿수 구하기
    for(i=1;(x/i)>=10;i*=10){}
    originalX=x;
    //자릿수 더하기
    for(;i>=1;i/=10){
        sum+=(x/i);
        x -=( (x/i)*i );
    }
    if(originalX%sum!=0)
        return false;
    return answer;
}