#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define OK    1
#define ERROR 0

typedef int SElemtype;
typedef int Status;

typedef struct 
{
    SElemtype *top;//栈顶指针
    SElemtype *base;//在栈构造之前和销毁之后为NULL
    int stacksize;//当前已分配栈的大小
}Sqstack;


Status InitStack(Sqstack *S)
{
    S->base = (SElemtype *)malloc(STACK_INIT_SIZE*sizeof(SElemtype));
    if(!S->base)
    {
        return ERROR;
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
//判栈是否为空
Status StackEmpty(Sqstack *S)
{
    if(S->top == S->base)
    {
        return OK;
    }
    return ERROR;
}

//判栈满
Status StackFull(Sqstack *S)
{
    if(S->top - S->base >= S->stacksize)
    {
        return OK;
    }
    return ERROR;
}

//栈顶
Status Gettop(Sqstack *S,SElemtype* e)
{
    if(StackEmpty(S))
    {
        return ERROR;
    }
    (*e) = *(S->top-1);
    return OK;
}

//压栈
Status PushStack(Sqstack *S,SElemtype e)
{
    if(StackFull(S))
    {
        S->base = (SElemtype *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemtype));
        if(!S->base)
        {
            return ERROR;
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
        
    }
    *(S->top++) =e;
    return OK;
}

//弹栈
Status PoStack(Sqstack *S,SElemtype *e)
{
    if(StackEmpty(S))
    {
        return ERROR;
    }
    (*e) = *(--S->top);
    return OK;
}

Status ClearStack(Sqstack *S)
{
    S->top = S->base;
    S->stacksize = 0;
    return OK;
}

int Length(Sqstack *S)
{
    return S->top - S->base;
}
Status Traverse(Sqstack *S)
{
    SElemtype *p;
    p = S->top - 1;
    while(p >= S->base)
    {
        printf("%d",*p);
        p--;
    }
    printf("\n");
    return OK;
}
int main()
{
    Sqstack L ;
    Sqstack *l = &L;
     SElemtype a;
     SElemtype *e = &a;
    InitStack(l);
    PushStack(l,1);
    PushStack(l,3);
    Traverse(l);
    PoStack(l,e);
    printf("%d",*e);
    return 0;
}
