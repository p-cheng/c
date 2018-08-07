#include <stdio.h>
#include <stdlib.h>


#define OK    1

#define ERROR 0

typedef char Elemtype;

typedef struct DualNode
{
    Elemtype data;
    struct DualNode *prior;
    struct DualNode *next;
}Node;
typedef struct DualNode * DuLinklist;
DuLinklist InitList(DuLinklist L)
{
    DuLinklist p, q;
    int i;
    L = (DuLinklist)malloc(sizeof(DuLinklist));
    if(!L)
    {
        return ERROR;
    }
    L->prior = L->next =NULL;
    p = L;
    for(i=0;i<26;i++)
    {
        q = (DuLinklist)malloc(sizeof(Node));

        if(!q)
        {
            return ERROR;
        }
        q->data = 'A' + i;
        q->prior = p;
        q->next = p->next;
        p->next = q;
        p = q;
    printf("%c\n",p->data);
    }
    p->next = L->next;
    L->next->prior = p;
    L->prior = p;
    return L;
}

DuLinklist Caesar(DuLinklist L,int i)
{
        if(i >0)
        {
            do
            {
                printf("%d\n",i);
                L = L->next;
            }while(--i);
        }
        else if(i<0)
        {
            do
            {
                printf("   +++ %d\n",i);

                L  = L->prior;

            }while(i++);

        }
        return L;
}

int main()
{
    DuLinklist head = NULL;
    int i ;
    int n;
    head=InitList(head);
   // printf("%c",head->next->data);
    printf("请输入一个整数:");
    scanf("%d",&n);
    printf("\n");
    head =Caesar(head,n);
    for(i=0;i<26;i++)
    {
        head = head->next;
        printf("%c ",head->data);
    }
    putchar(10);
    return 0;
}

