#include <stdio.h>
#include <stdlib.h>
//带头结点链栈
typedef struct Snode
{
    int data;
    struct Snode *next;
} Snode, *LinkStack;

bool InitLinkStack(LinkStack S)
{
    //头结点分配内存
    S = (Snode *)malloc(sizeof(Snode));
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
}
//查栈顶元素
int GetTop(LinkStack S)
{
    if (S == NULL)
        return -1;
    return S->next->data;
}
// 读取栈中所有元素
void GetAllElem(LinkStack S)
{
    while (S->next)
    {
        S = S->next;
        printf("%d ", S->data);
    }
}
// 入栈
bool Push(LinkStack S, int e)
{
    Snode *q;
    q = (Snode *)malloc(sizeof(Snode));
    if (q == NULL)
        return false; //内存分配失败
    q->data = e;
    q->next = S->next; //可看链表后插
    S->next = q;
    return true;
}
// 出栈
int Pop(LinkStack S)
{
    int e;
    if (S->next == NULL)
        return false; //是否有栈顶元素
    Snode *q = S->next;
    e = q->data;
    S->next = q->next; // 前中后 前->后
    return e;
}

int main()
{
    LinkStack S;
    InitLinkStack(S);
    for (int i = 7; i > 2; i--)
    {
        Push(S, i);
    }
    printf("栈顶元素->%d\n", GetTop(S));
    printf("依次打印栈中上到下元素:");
    GetAllElem(S);
    printf("\n删除栈顶元素->%d\n", Pop(S));
    return 0;
}