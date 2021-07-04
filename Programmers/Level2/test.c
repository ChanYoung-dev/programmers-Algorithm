/*
 1️⃣tip
    1
   2 9
  3 10 8
 4  5 6 7 
 이런식으로 배열을 생각하지말고
 
 1
 2 9
 3 10 8
 4 5  6 7
 이 배열로 생각하자!
 
 2️⃣tip
 n번이면
 👇방향으로 N번
 👉방향으로 N-1번
 👆대각성방형으로 N-2번
 👇방향으로 N-3번
 👉방향으로 N-4번
 👆대각성방형으로 N-5번
 .....
 방향으로 1번

 이기때문에 3번의 방향성을 반복된다는 것을 알 수 있다.i%3을 이용하자!
 
  3️⃣tip
  n번일 경우에
  n번 반복 n-1번반복 ~~ 1번반복이기때문에
  전체돌림 횟수가 n번 (for i <n)
  안쪽돌림 n에서 1씩줄어듬 (for j)
 
  4️⃣tip
  2차원 배열을 입력할때
  int **arr=(int**)malloc(sizeof(int*)*n);
    for(i=0 ; i< n ; i++)
        arr[i]= (int*)malloc((i+1)*sizeof(int));
        
  arr와 answer
  즉,2차원배열과 1차원배열을 연결하는 방법은 무엇일까
  

*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    int i=0;
    int j;
    int x=-1;
    int y=0;
    int count=1;
    int z=0;
    int ansnum=0;
    int **arr=(int**)malloc(sizeof(int*)*n);
    for(i=0 ; i< n ; i++)
        arr[i]= (int*)malloc((i+1)*sizeof(int));
        
    for(i=0;i<n;i++)
        for(j=i;j<n;j++){
            if(i%3==0)
                x++;
            else if(i%3==1)
                y++;
            else
                {
                    x--;
                    y--;
                }
            arr[x][y]=count++;
            }
    for(i=0;i<n;i++){
        for(j=n-i-1,z=0;j<n;j++,z++){
            //printf("i= %d, j = %d, z = %d ",i, j,z );
            *(answer+(ansnum++))=*(arr[i]+z);
            //printf("%3d   ",*(arr[i]+z));
            
        }
    //printf("\n");
    }
    return answer;
}