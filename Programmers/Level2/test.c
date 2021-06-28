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