/*
(x1,y1)  -------  (x1,y2)
|                       |
|                       |
|                       |
|                       |
|                       |
(x2,y1)  -------  (x2,y2)

ex)
8   9  10
14     16
20  21 22
->방향
----------
8 9 SWAP

9   8  10
14     16
20     22
26  27 28
-----------
아래방향
---------
9 10 SWAP
---------
10   8  9
14     16
20     22
26  27 28

10 16 SWAP

16   8  9
14     10
20     22
26  27 28

16 22 SWAP

22  8  9
14     10
20     16
26  27 28
-----------

이런식으로 진행한다.

*/




#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SWAP(x,y,temp) ( (temp)=(x),(x)=(y),(y)=(temp) )

// queries_row_len은 2차원 배열 queries의 행(세로) 길이입니다.
// queries_col_len은 2차원 배열 queries의 열(가로) 길이입니다.
// queries[i][j]는 queries의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*queries_row_len);
    int i,j,temp,k,l,h,m,n;
    int listvalue=0;
    int num;
    int list[rows][columns];
    int query;
    int min,first;
    
    //각 행렬에 초기원소값 대입
    for(k=0;k<rows;k++){
        for(l=0;l<columns;l++){
            list[k][l]=k*columns+l+1;
            if(queries_row_len!=1){
                //printf("%d ",list[k][l]);
            }
        }
        //printf("\n");
    }
    // 행렬이 전체회전을 몇번하는지 -> [[2,2,5,4],[3,3,6,6],[5,1,6,3]] -> 총 세번
    for(num=0;num<queries_row_len;num++){
        //회전을 한번만 할때
        if(queries_row_len==1){
            answer[0]=list[queries[num][0]-1][queries[num][1]-1];
            break;
        }
        i=0;
        j=0;
        //회전시키기
        for(; i<(queries[num][3]-queries[num][1]); i++ )
            SWAP(list[queries[num][0]-1][queries[num][1]-1],list[queries[num][0]-1+j][queries[num][1]-1+i],temp);
        for(; j<(queries[num][2]-queries[num][0]); j++ )
            SWAP(list[queries[num][0]-1][queries[num][1]-1],list[queries[num][0]-1+j][queries[num][1]-1+i],temp);
        for(;i>0;i--)
            SWAP(list[queries[num][0]-1][queries[num][1]-1],list[queries[num][0]-1+j][queries[num][1]-1+i],temp);
        for(;j>0;j--)
            SWAP(list[queries[num][0]-1][queries[num][1]-1],list[queries[num][0]-1+j][queries[num][1]-1+i],temp);
        //최소값찾기
        int answerlist[400];
        i=0;
        j=0;
        h=0;
        //테두리의 각 원소들을 answerlist에 대입
        for(;i<(queries[num][3]-queries[num][1]);i++,h++)
            answerlist[h]=list[queries[num][0]-1+j][queries[num][1]-1+i];
        for(;j<(queries[num][2]-queries[num][0]);j++,h++)
            answerlist[h]=list[queries[num][0]-1+j][queries[num][1]-1+i]; 
        for(;i>0;i--,h++)
            answerlist[h]=list[queries[num][0]-1+j][queries[num][1]-1+i];
        for(;j>0;j--,h++)
            answerlist[h]=list[queries[num][0]-1+j][queries[num][1]-1+i];
        //초기최소값을 첫번째 원소로 설정
        min=answerlist[0];
        //최소값과 원소 비교후 제일 작은 최소값 찾기
        for(h=0;h<(queries[num][3]-queries[num][1]+queries[num][2]-queries[num][0])*2;h++)
        {
            if(answerlist[h]<min)
                min=answerlist[h];
        }
        answer[num]=min;
    }
    return answer;
}