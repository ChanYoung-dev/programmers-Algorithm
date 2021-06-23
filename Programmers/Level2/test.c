#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void selection_sort(int list[], int n){
  int i, j, min, temp;

  // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
  for(i=0; i<n-1; i++){
    min = i;

    // 최솟값을 탐색한다.
    for(j=i+1; j<n; j++){
      if(list[j]<list[min])
        min = j;
    }

    // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
    if(i != min){
        SWAP(list[i], list[min], temp);
    }
  }
}



int* solution(int **v, size_t v_row_len, size_t v_col_len) {
    //int arr[2];
    int m=2;
    int n=1;
    printf("m : %d, n : %d \n",m,n);
    int* answer = (int*)malloc(sizeof(int)*2);
    answer[0]=m; //arr[0]=m;
    answer[1]=n; //arr[1]=n;
    selection_sort(answer,2);
    printf("m : %d, n : %d \n",m,n);
    //printf("arr[0] :%d \n",m);
    //answer=&arr[0];
    printf("answer[0] :%d", answer[0]);
    return answer;
}