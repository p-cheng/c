/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 14时41分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef    struct node
{
    ElementType  data;
    struct node *next;
}Node;
typedef Node *List;
List MakeEmpty()//创建一个空链表
{
    List head=NULL;
    head=(List)malloc(sizeof(Node));//head=(List)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head; 
}
/*typedef link_table;
List MakeEmpty2()
{ 
    List link_table =(List)malloc(sizeof(Node));
    link_table -> data =0;
    link_table -> next =NULL;
    return link_table;
    
}*/
void PrintList(List L )//打印一个链表
{
    List tmp=L;
    while(tmp != NULL)
    {
        printf("%d\t",tmp->data);
        tmp = tmp-> next;
    }
    putchar(10);
}

Node *Inert(List L,ElementType e)//在尾部插入一个链表
{ 
    List p=L;
    List t;
    t=(List)malloc(sizeof(Node));
    t->data=e;
    t->next=NULL;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=t;
}
void Inert2(List *L,ElementType e)
{
    List t =(List)malloc(sizeof(Node));
    t->data = e;
    t->next =*L;
    *L=t;
}

void Delet_Node(List *L, ElementType e)
{
    List temp = *L;
    /*if((*L)->data == e)
    {
        *L = (*L)->next;
        (*L)->next = NULL;
        free(temp);
    }*/
    while(temp->next->data != e)
    {
        temp = temp->next;
    }
    if((*L)->next == NULL)
    {
        printf("none the data %d\n",e);
    }
    else
    {
        temp = (*L)->next;
        (*L)->next = (*L)->next->next;
        free(temp);
    }
}
int main()
{;
    List p = NULL;
    p = MakeEmpty();
    
    Inert(p,2);
    Inert(p,2);
    Inert2(&p,4);

    Delet_Node(&p, 2);
    PrintList(p);
    return 0;
}
