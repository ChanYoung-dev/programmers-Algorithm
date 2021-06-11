#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int i;
    
    for(i=1;n/i>=10;i*=10){}
    while(i>=1)
    {
        answer += ( n / i );
        n -= n / i * i ;
        i/=10;
    }
    
        
    
    
    
    return answer;
}