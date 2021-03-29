#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode *link;
typedef struct Lnode
{
    ElemType data;
    link next;
} Lnode;
typedef struct LinkList
{
    link first, curr, last; //链表表首指针 当前指针 表位指针
} LinkList;
//带头结点版本 创销 增删改查 表长度
bool ListInit(LinkList L)
{
    //创建头结点
    L = (Lnode *)malloc(sizeof(Lnode));
    if (L == NULL)
        return false; //内存分配失败
    L->next = NULL;
    return true;
}
bool ListDestory(LinkList L)
{
    L = NULL;
    free(L);
    return false;
}

bool ListInsert(ElemType x, LinkList L)
{
}
int main()
{
    LinkList L;
    return 0;
}