#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long w, long long h) {
    long long answer = 1;
    long long maxCheck=0;
    long long i;
    long long num;
    
    //소수 구하기
    num= ( w>h ) ? h : w;
    for( i=num ; i>0; i--){
        if( ( (w%i) ==0 ) && ( (h%i) ==0 ) ){
            maxCheck=i;
            break;
        }
    }
    
    answer = w*h-( maxCheck * ( (w/maxCheck) + (h/maxCheck)-1 ) );
    //answer = (w*h)-(w+h-maxCheck);
    
    return answer;
}