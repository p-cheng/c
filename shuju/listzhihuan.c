#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}Node;

Node* MakeEmpty()
{
    Node* head = (Node*)malloc(sizeof( Node));

    head->data =0;
    head->next =NULL;
    return head;

}
Node* MakeList()//创建链表
{
    int i ,len;
    printf("请输入你要创建的链表的长度\n");
    scanf("%d",&len);
    Node* head = NULL;
    head = (Node *)malloc(sizeof( Node));
    head->data = 0;
    head->next= NULL;
    Node* tail = head;
    for(i=0;i<len;i++)
    {
        int val;
        printf("请输入存入的值\n");
        scanf("%d",&val);
        Node* Newlist = NULL;
         Newlist = (Node*)malloc(sizeof( Node));
        Newlist->data = val;
        Newlist->next = NULL;
        tail->next = Newlist;
        tail = Newlist;
        head->data++;
    }
    putchar(10);
    return head;
}
void PrinList(Node* head)//打印链表
{
    if(head->next == NULL)
    {
        printf("链表为空\n");
        return ;
    }
    head = head->next;

    int i = 0;
    while(head != NULL)
    {
        printf("第%d个数据 %d\n",i,head->data);
        head = head->next;
        i++;
     }
}
Node* fun(Node *head)//循环链表反转
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    if(head->next == NULL)
    {
        printf("head->next is NULL\n");
    }
    Node *p = NULL;
    Node* next = NULL;
    Node* h = head->next;
    while(h != NULL)
    {

        printf("进行反转\n");
        next = h->next;
        h->next = p;
        p = h;
        h = next;
    }
    head->next = p;
    return head;

}
 
Node *rever(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;

    }
    Node * Newh = rever(head->next);
    
        head->next->next=head;
        head->next=NULL;
        return Newh;
    
}
int main()
{
    Node* l = NULL;
    l = MakeList();

    //PrinList(l);
    PrinList(l);
    l= fun(l);
    l= rever(l);
    PrinList(l);
    return 0;
}
