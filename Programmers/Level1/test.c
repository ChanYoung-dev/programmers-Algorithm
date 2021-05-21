#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
//소수인지 판단하여 소수이면 result 1 증가
int totalprime(int number,int result){
    int factorCheck;
    int isprime=0;
    //짝수가 아니면
    if(number%2!=0)
            {
                // 7인경우 소수판별
                if(number==7){
                    result++;
                    return result;
                }
                // 3,5,7 ..~ 제곱근 으로 나누어지면 소수이다
                for(factorCheck=3 ; factorCheck<=sqrt(number) ; factorCheck+=2){
                    //소수가 아닌경우
                    if( number%factorCheck==0){
                        isprime=1;
                        break;
                    }
                }
                //소수인경우
                if(isprime!=1)
                    result++;
            }
    return result;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    // 총결과값
    int answer = 0;
    // 배열에 있는 숫자들의 합/ 검사할숫자
    int sum;
    //반복문에 쓰일 변수
    int i,j,k;
    //nums배열 원소들 더하기
    for(i=0;i<nums_len-2;i++){
        for(j=i+1;j<nums_len-1;j++){
        for(k=j+1;k<nums_len;k++){
            sum=nums[i]+nums[j];
            sum+=nums[k];
            //소수인지 판별
            answer=totalprime(sum,answer);
            //다음 판별할 숫자를 위해 초기화
            sum=0;
            }
        }
    }
    return answer;
}