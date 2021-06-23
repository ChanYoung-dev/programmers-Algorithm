#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// v_row_len은 2차원 배열 v의 행(세로) 길이입니다.
// v_col_len은 2차원 배열 v의 열(가로) 길이입니다.
// v[i][j]는 v의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int **v, size_t v_row_len, size_t v_col_len) {
    //int arr[2];
    int m=1;
    int n=1;
    printf("m : %d, n : %d \n",m,n);
    int* answer = (int*)malloc(sizeof(int)*2);
    answer[0]=m; //arr[0]=m;
    answer[1]=n; //arr[1]=n;
    //printf("arr[0] :%d \n",m);
    //answer=&arr[0];
    printf("answer[0] :%d", answer[0]);
    return answer;
}