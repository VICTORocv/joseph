//
//  main.c
//  joseph
//
//  Created by 郭悟清 on 2016/10/11.
//  Copyright © 2016年 郭悟清. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int    data;
    int    num;
    struct node*  next;
}node,*LIST;
LIST CreateList(int n)
{
    LIST p,q,head;
    p=(node*)malloc(sizeof(node));
    head=p;
    scanf("%d",&p->data);
    p->num=1;
    for(int i=2;i<n+1;i++)
    {
        q=(node*)malloc(sizeof(node));
        scanf("%d",&q->data);
        q->num=i;
        p->next=q;
        p=q;
    }
    p->next=head;
    return head;
}
LIST DeleteList(LIST L)
{
    LIST   T=L;
    while(L->next!=T)               //将指针定位到要删除元素的前一位置。若不要求单向链表，可用双向循环链表，减少时间复杂度
    {
        L=L->next;
    }
    L->next=T->next;
    free(T);
    L=L->next;
    return L;
}
void Joseph(LIST L,int m,int n)     //递归函数Joseph，m为报数上限值，n为当前人数
{
    if(n==1)
    {
        printf(" %d ",L->num);
        L=DeleteList(L);
    }
    else
    {
        int i=1;
        while (L&&i<m)
        {
            L=L->next;
            i++;
        }
        printf(" %d ",L->num);
        m=L->data;
        L=DeleteList(L);
        --n;                         //每次出列一人，n的值减1
        Joseph(L,m,n);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    LIST l=CreateList(7);
    Joseph(l,20,7);                  //调用递归函数
    return 0;
}
