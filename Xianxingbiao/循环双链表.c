#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *next, *prior;
} DNode, *CLinkList;

int InitList(CLinkList L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return 0;
    L->next = L;
    L->prior = L;
    return 1;
}

ElemType isTail(CLinkList L, DNode *p)
{
    if (p->next == L)
        return 1;
    else
        return 0;
}

ElemType isEmpty(CLinkList L)
{
    if (L->next == L)
        return 1;
}

ElemType InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    s->next->prior = s;
    s->prior = p;
    p->next = s;
    return 1;
}
ElemType DeleteNextDNode(DNode *p)
{
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}
ElemType CreateDLinkList(CLinkList L, ElemType e)
{
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    if (L->next != L)
    {
        s->next = L->next;
        s->next->prior = s;
    }
    else
    {
        printf("%d", s->data);
        s->next = L;
        s->prior = L;
        L->prior = s;
    }
    s->prior = L;
    L->next = s;
    return 1;
}
int main()
{
    CLinkList L;

    printf("%d\n", InitList(L));
    printf("%d\n", CreateDLinkList(L, 5));
    printf("%d", L->next->data);
    return 0;
}
