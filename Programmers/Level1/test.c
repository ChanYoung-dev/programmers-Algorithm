#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int solution(int n) {
    int i = 0,answer = 0,tenN = 1, arr[20];
    for(;n!=0;arr[i]=n%3,n/=3,i++){}
    for(--i;i>=0;answer+=arr[i]*tenN,i--,tenN*=3){}
    return answer;
}