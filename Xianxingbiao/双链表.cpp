#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *Dlinklist;

// 初始化双链表 带头
bool InitDLinkList(Dlinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}
// p节点后插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    if (p->next != NULL) //判断是否有后续节点
        s->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
// 按位序插入结点 双链表找到结点的前驱结点执行后插操作
// 前插操作同理

// 双链表删除操作
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    // p 指针后面是 q指针 删除q
    DNode *q = p->next; //先创q指针指向p后继
    if (q == NULL)
        return false;       //p结点没有后继
    p->next = q->next;      //指向q后继
    if (q->next != NULL)    //判断q后继存在
        q->next->prior = p; //q后继前指针域指向p
    free(q);
    return true;
}

//指针释放
void DestoryList(Dlinklist &L)
{
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);  //释放头结点
    L = NULL; //头指针指向NULL
}
// 遍历双链表 按位计数器
// while(p!=NULL){
//     p=p->next;  /prior
// }
void test()
{
    Dlinklist L;
    InitDLinkList(L);
}

int main()
{
    test();
    return 0;
}