#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* s) {
    char* arr=(char*)malloc(strlen(s));
    int* answer = (int*)malloc(sizeof(int) * 2);
    int i,j,num,size;
    int zero_count=0;
    int zero_total=0;
    strcpy(arr,s); // 내용을 복사하는 것
    //arr=s; ->주소를 복사 하는 것
    int len=strlen(s);
    //num은 회차이다.
    for(num=0; len!=1; num++){
        int *ten_to_two= (int*)calloc(size,sizeof(int));
        size=1;
        zero_count=0;
        //0의 갯수 Count
        for(i=0;arr[i]!='\0';i++)
            if(arr[i]=='0')
                zero_count++;
        //전체 0의 갯수
        zero_total+=zero_count;
        //len = 기존 배열길이 - 0의 원소 갯수
        len= i-zero_count;
        //len10진수를 2진수로 바꾸기
        if(len!=1)
        {
            // 배열에 원소 넣기 ex) 11 => 1 1 0 1 (2로 나누고 나머지 값) 
            for (i = 0; len != 0; i++) {
                ten_to_two[i] = len % 2;
                len /= 2;
                if (len != 0) {
                    size++;
                    ten_to_two = realloc(ten_to_two, sizeof(int)*size);
                }
            }
            // 배열 원소 거꾸로 출력 , 결과값을 arr배열에 저장
            for (i = size - 1,j=0; i >= 0; i--,j++) {
                arr[j]=ten_to_two[i]+'0';
            }
            arr[j]='\0';
            free(ten_to_two);
        }

    }
    answer[0]=num;
    answer[1]=zero_total;
    
    return answer;
}