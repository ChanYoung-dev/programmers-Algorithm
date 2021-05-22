#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//약수의 개수 구하기
int factoramount(int number){
    int i=1;
    int sum=0;
    for(i;i<=number/2;i++)
        if(number%i==0)
            sum++;
    return sum+1;
}


int solution(int left, int right) {
    int answer = 0;
    int j=0;
    for(j = left;j <=right;j++)
        (factoramount(j)%2) ? (answer += (-1*j)) : (answer += j);
    return answer;
}