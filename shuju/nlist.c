#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}Node;

typedef Node * list;

list Makelist()//创建空链表
{
    list head = NULL;
     head = (list)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

list InsertH(list head, int x)//头插法
{
    list p = (list)malloc(sizeof(Node));
    p->data = x;
    p->next = head;
    head = p;
    return head;
    
}
void InsertT(list head,int x)//尾插法
{
    list l;
    l = head;
    while(l->next!= NULL)
    {
        l = l->next;
    }
    list p = (list)malloc(sizeof(Node));
    p->data = x;
    p->next =NULL;
    l->next = p;
}

void Deletelsit(list head,int x)
{
    list l = head;
    if(l->data == x)
    {
        head = l->next;
        free(l);
        return;
    }
    while(l->next->data != x)
    {
        l = l->next;
    }
    if( l->next == NULL)
    {
        printf("你删除的数据不存在\n");
        return;
    }
    else
    {
        list q;
        q = l->next;
        l->next = q->next;
        free(q);
    }
}
list Find(list head, int x)//查找
{
    list p;
    p = head;
    while(p->data != x)
    {
        p = p->next;
    }
    if(p->data != x && p->next == NULL)
    {
    
        printf("你查找的数据不存在\n");
        return NULL;
    }
    else
    {
        printf("你所查找的数据%d \n",p->data);
        return p;
    }
}
void Printlist(list head)
{
    list p;
    int i = 1;
    p = head;
    if(p == NULL)
    {
        printf("链表为空\n");
        return;
    }
    do
    {
        printf("第%d个数据为%d\n",i, p->data);
        p = p->next;
        i++;
    }while(p != NULL);
    return;
}

list fz(list head)//链表的反转
{
    printf("进入fz\n");
    if(head==NULL || head->next==NULL)
    {
        printf("进入if\n");
        return head;
    }
    list p = NULL,next = NULL;
    while(head != NULL)
    { 
        printf("进入while\n");
        next = head->next;
        head->next = p;
        p = head;
        head = next;
    }
    return p ;
        
}
int main()
{
    list x  = NULL;
    x=Makelist();
    Printlist(x);
    x=InsertH(x,4);
    Printlist(x);
    InsertT(x,5);
    Find(x,4);
    Find(x,5);
   x=fz(x);
    Printlist(x);
    return 0;
}
