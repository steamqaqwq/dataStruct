#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{ //链式队列结点
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear; //对头指针和队尾指针
} LinkQueue;

// 带头结点
// 初始化队列
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
    // front rear 指向头结点
}
// 不带头结点 初始化队列
void InitQueue1(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
    // front rear 指向NULL
}
// 带头 判断队列是否空
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

//不带头
bool IsEmpty1(LinkQueue Q)
{
    if (Q.front == NULL)
        return true;
    else
        return false;
}

// 入队 带头 尾插法
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; //连接头和新的
    Q.rear = s;       //修改表位指针到新节点
}
//  入队 不带头
void EnQueue1(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    //插入第一个元素需要处理两个指针 将第一个元素当头结点（大概)
    if (Q.front == NULL)
    {
        Q.front = s;
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s;
        Q.rear = s;
    }
    Q.rear->next = s; //连接头和新的
    Q.rear = s;       //修改表位指针到新节点
}

// 带头结点 出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front; //归位！
    free(p);              //释放p结点
    return true;
}

// 不带头结点 出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if (Q.rear == p) //头尾指向最后一个结点
    {
        Q.rear = NULL;  //归位！
        Q.front = NULL; //归位！
    }
    free(p); //释放p结点
    return true;
}

// 队列满时？链式不会