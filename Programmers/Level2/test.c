#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef char Data;
typedef struct _Node{
    Data data;
    struct _Node * Next;
}Node;
typedef struct _lQueue{
    Node * front;
    Node * rear;
}LQueue;
typedef LQueue Queue;

void QueueInit(Queue * pq)
{
    pq->front=NULL;
    pq->rear=NULL;
}

int QisEmpty(Queue * pq)
{
    if(pq->front==NULL)
        return 1;
    else
        return 0;
}

void Enqueue(Queue * pq,Data data)
{
    Node * newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->Next=NULL;
    if(QisEmpty(pq)){
        pq->front=newNode;
        pq->rear=newNode;
    }
    else{
        pq->rear->Next=newNode;
        pq->rear=newNode;
    }
}

Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;
    if(QisEmpty(pq)){
        printf("Queue Memory Error");
        exit(-1);
    }
    delNode=pq->front;
    retData=pq->front->data;
    pq->front=pq->front->Next;
    
    free(delNode);
    return retData;
}

Data QPeek(Queue * pq)
{
    if(QisEmpty(pq)){
        printf("Queue Memory Error");
        exit(-1);
    }
    
    return pq->front->data;
    
    
    
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    
    Queue q;
    QueueInit(&q);
    
    
    Enqueue(&q,1);
    
    Enqueue(&q,2);
    
    Enqueue(&q,3);
    
    Enqueue(&q,4);
    
    Enqueue(&q,5);
    
    while(!QisEmpty(&q))
        printf("%d",Dequeue(&q));
    
    return answer;
}