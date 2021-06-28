#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef char Data;
typedef struct _Node{
    Data data;
    struct _Node * Next;
}Node;
typedef struct _liststack{
    Node * head;
}Liststack;
typedef Liststack Stack;
Data* rotate(Data *copy,int len);
void stackInit(Stack * pstack){
    pstack->head=NULL;
}
int SisEmpty(Stack * pstack){
    if(pstack->head==NULL)
        return 1;
    else
        return 0;
}
void SPush(Stack * pstack,Data data){
    Node * New=(Node*)malloc(sizeof(Node));
    New->data=data;
    New->Next=pstack->head;
    pstack->head=New;
}
Data SPop(Stack * pstack){
    Data rdata;
    Node * rnode;
    
    if(SisEmpty(pstack)){
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    rdata=pstack->head->data;
    rnode=pstack->head;
    pstack->head=pstack->head->Next;
    free(rnode);
    return rdata;
}
Data SPeek(Stack * pstack){
    if(SisEmpty(pstack)){
        printf("Stack Memory Error!");
        exit(-1);
    }
    return pstack->head->data;
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    Data *s_copy2=s;
    
    int x=1;
    Stack stack;
    stackInit(&stack);
    
    int i,j;
    for(j=0;j<strlen(s);j++)
    {
        x=1;
        for(i=0;i<strlen(s);i++)
        {
            if(s_copy2[i]=='[' || s_copy2[i]=='(' || s_copy2[i]=='{')
                SPush(&stack,s_copy2[i]);
            else{
                if(!SisEmpty(&stack)){
                    if(s_copy2[i]==']' && SPeek(&stack)=='[')
                        SPop(&stack);
                    else if(s_copy2[i]=='}' && SPeek(&stack)=='{')
                        SPop(&stack);
                    else if(s_copy2[i]==')' && SPeek(&stack)=='(')
                        SPop(&stack);
                    else{
                        x=0;
                        break;
                    }
                }
                else{
                    x=0;
                    break;
                }
            }
            
        }
        if(!SisEmpty(&stack))
            x=0;
        if(x!=0){
            printf("answer : %d",++answer);
        }
        s_copy2=rotate(s_copy2,strlen(s));
    }   
    return answer;
}
char* rotate(char *copy,int len){
    char *s_copy=(char*)malloc(len);
    int i;
    for(i=0;i<len;i++)
        s_copy[i]=copy[i+1];
    s_copy[len-1]=copy[0];
    
    //printf("함수안에서의 배열 : ");
    //for(i=0;i<len;i++)
        //printf("%c",s_copy[i]);
        
    //printf("\n"); 
    
    return s_copy;
}