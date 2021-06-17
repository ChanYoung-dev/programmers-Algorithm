#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    int i;
    
    for(i=0;i<=500;i++){
        printf("%d->",num);
        //짝수일때
        if(num%2==0)
            num/=2;
        else if(num==1)
            return i;
        //홀수일때
        else if(num%2==1)
            num = num*3+1;
        //횟수가 500이상일때
        
        printf("%d\n",num);
    }
    printf("최종 : %d\n",num);
    if(i>500)
        return -1;
}