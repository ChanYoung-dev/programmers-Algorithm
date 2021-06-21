#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x,y,temp) ((temp)=(x),(x)=(y),(y)=(temp))
// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1);
    //char* str_arr[numbers_len]; 
    int* arr[numbers_len];
    int digit;
    int i=1; int j;
    int k;
    int o,p;
    int max;
    int m,n=0;
    int arr_factor[50];
    int *temp;
    
    for(k = 0 ; k<numbers_len; k++){
        
        for(digit=1;numbers[k]/digit>=10;digit*=10,i++){}
        
        for( j=0 ; digit>=1 ; digit/=10, j++){
            arr_factor[n+j]= numbers[k]/digit;
            printf("%d : %d \n",j, arr_factor[n+j]);
            numbers[k] = numbers[k] - arr_factor[n+j]*digit;
            }
        arr_factor[n+j]=10;    
        arr[k] = &(arr_factor[n]);
        n+=j+1;
        if(k==numbers_len-1)
            for(m=0;m<numbers_len;m++){
                printf("%d\n",*(arr[m]));
            }
    }
    
    
    printf("바꾸기전 : \n");
    for(m=0;m<numbers_len;m++){
        for(i=0;*(arr[m]+i)!=10;i++)
                printf("%d",*(arr[m]+i));
        printf("\n");
    }
    
    
    
    for(o=0;o<k-1;o++){
        max=o;
        for(p=o+1;p<k;p++){
            if( *(arr[o]) < *(arr[p]) ){
                max=p;
                printf("arr[%d] : %d < arr[%d] : %d \n",o, *(arr[o]), p, *(arr[p]));
            }
            
            
            
            
        }
        if(max!=o ){
            temp=arr[o];    
            arr[o]=arr[max];
            arr[max]=temp;
        }
        
        for(m=0;m<numbers_len;m++){
            for(i=0;*(arr[m]+i)!=10;i++)
                    printf("%d",*(arr[m]+i));
            printf("\n");
        }
        
        
            
    }
    printf("바꾼후 : \n");
    for(m=0;m<numbers_len;m++){
        for(i=0;*(arr[m]+i)!=10;i++)
                printf("%d",*(arr[m]+i));
        printf("\n");
        
        
    }
    
    for(o=0;o<k-1;o++){
        max=o;
        for(p=o+1;p<k;p++){
            if(*(arr[o]) == *(arr[p]) ){
                printf("앞자리수가 같습니다.\n");
                for(i=0;arr[o]+i==arr[p]+i ;i++){}
                printf("%d vs %d\n",*(arr[o]+i+1), *(arr[p]+i+1));
                if( ( *(arr[o]+i+1) < *(arr[p]+i+1)) && *(arr[p]+i+1)!=10 ){
                    printf("체인지 %d 와 %d\n",*(arr[o]+i+1), *(arr[p]+i+1));
                    max=p;
                    temp=arr[o];    
                    arr[o]=arr[max];
                    arr[max]=temp;
                    for(m=0;m<numbers_len;m++){
                        for(i=0;*(arr[m]+i)!=10;i++)
                        printf("%d",*(arr[m]+i));
                        printf("\n");
                    }
                    printf("\n----------\n");
                }  
            }
            
            
            
            
        }
        
        for(m=0;m<numbers_len;m++){
            for(i=0;*(arr[m]+i)!=10;i++)
                    printf("%d",*(arr[m]+i));
            printf("\n");
        }
        
        
            
    }
    
    return answer;
}

