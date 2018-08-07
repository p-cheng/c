#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;

}Node;
typedef Node* list;
list MakeEmpty()//创建空链表
{

    list head = NULL;
    head = (list)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
list MakeList()//创建链表
{
    int i ,len;
    printf("请输入你要创建的链表的长度\n");
    scanf("%d",&len);
    list head = NULL;
    head = (list)malloc(sizeof(Node));
    head->data = 0;
    head->next= NULL;
    list tail = head;
    for(i=0;i<len;i++)
    {
        int val;
        printf("请输入存入的值\n");
        scanf("%d",&val);
        list Newlist = NULL;
         Newlist = (list)malloc(sizeof(Node));
        Newlist->data = val;
        Newlist->next = NULL;
        tail->next = Newlist;
        tail = Newlist;

    }
    putchar(10);
    return head;
}
void PrinList(list head)//打印链表
{
    if(head->next == NULL)
    {
        printf("链表为空\n");
        return;
    }
    list p;
    p = head->next;
    int i = 1;
        while(p != NULL)
        {

            printf("第%d个数据 %d\n",i,p->data);
            p = p->next;
            i++;
        }
    
    return;
}
int Insert(list head, Elemtype e,int i)//向第i个位置插入数据
{
     list NewList = (list)malloc(sizeof(Node));
     NewList->next = NULL;
     NewList->data = e; 
     int j = 1;
     list p;
     p = head;
     while(p && j<i)
     {
         p = p->next;
         j++;
     }
     if(!p || j>i)
     {
         return -1;
     }
    NewList->next=p->next;
    p->next = NewList;
    return 0;
}
void Delete(list head, Elemtype e)//删除的一个=e的数据
{
    list p,q;
    p  = head;
    while(p->next->data != e)
    {
        p = p->next;
    }
    if(p->next == NULL)
    {
        printf("没有数据%d\n",e);
        
    }
    else
    {
         q = p->next;
         p->next = q->next;
         free(q);
            
    }
}
list Find(list head,Elemtype e)//查找第一个=e的数据
{
   list p;
   p = head->next;
   while(p->data != e)
   {
       p = p->next;
   }
    if(p == NULL)
    {
        printf("你所查找的元素不存在%d\n",e);

    }
    return p;

}
void ListEmpty(list head)//判断链表是否为空
{
    if(head->next == NULL)
    {
        printf("这个链表为空\n");
    }
    else
    {
        printf("链表有数据存放\n");
    }
    return;
}

int main()
{
    list p = NULL;
    list q = NULL;
    p = MakeList();
    ListEmpty(p);
    Insert(p,4,3);
    q= Find(p,1);
    printf("存放的值 %d \n",q->data);
    Delete(p,2);
    PrinList(p);
    return  0;
}
