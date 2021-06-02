#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    int i =0,k = 0, j;
    int h = 0;
    int min=0, temp;
    // 순서관계없이 n개 중 2개를 선택 nC2 => (n*n-1)/2
    int len = (numbers_len)*(numbers_len-1)/2;
    int* answer = (int*)malloc(sizeof(int)*len);
    int* arr = (int*)malloc(sizeof(int)*len);
    //
    for(i;i<numbers_len-1;i++){
        for(j=i+1;j<numbers_len;j++,k++){
            answer[k]=numbers[i]+numbers[j];
            printf("answer =  %d + %d = %d\n",numbers[i],numbers[j],answer[k]);
        }
    }
    for(i=0;i<len;i++)
        printf(" %d, ",answer[i]);
    printf("\n ------------------ \n");
    //큰순서로 나열하기 (선택정렬)
    for(i=0,h=0; i<k-1; i++){
        min = i;
        for(j=i+1; j<k; j++){
            if(answer[j]<answer[min])
                min = j;
        }
        if(i != min){
            SWAP(answer[i], answer[min], temp);
        }
        arr[h]=answer[i];
        printf("%d번째 %d 삽입 ",h+1,arr[h]);
        if(arr[h]!=arr[h-1])
        {
            h++;
        }
    }
    printf("arr[%d]번쨰 : %d, answer[%d]번째: %d",h,arr[h],i,answer[i]);
    arr[h]=answer[i];
    printf("arr[h+1] : %d",arr[h]);
    for(i=0;i<len;i++)
        printf(" %d, ",answer[i]);
    printf("\n ------------------ \n");
    for(i=0;i<h;i++)
        printf(" %d, ",arr[i]);
    /*
    //중복제거
    for(i=0,h=0;i<k;i++,h++){
        if(answer[i-1]==answer[i]){
            h--;
            continue;
        }
        arr[h]=answer[i];
    }
    */
        
    return arr;
}