#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int part,a=0;
    int i,j,k,m;
    for(i=0;i<nums_len-2;i++)
    {
        for(j=i+1;j<nums_len-1;j++){
        for(k=j+1;k<nums_len;k++){
            part=nums[i]+nums[j];
            part+=nums[k];
            if(part%2!=0)
            {
                if( part==7){
                    answer++;
                    break;
                }
                
                for(m=3 ; m<=sqrt(part) ; m+=2){
                    if( part%m==0){
                        a=1;
                        break;
                    }
                }
                if(a!=1)
                {
                    printf("숫자%d는 소수입니다.",part);
                    answer++;
                }
                
            }
            part=0;
            a=0;
            }
            
        }
    }
    
    
    return answer;
}