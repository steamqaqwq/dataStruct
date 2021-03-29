#include <stdio.h>
#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int front, rear; //对头指针指向对头元素
    // 队尾指针指向队尾下一个元素
} SqQueue;

void InitQueue(SqQueue &Q, int x)
{
    Q.rear = Q.front = 0; //队尾队头指向0
}

// 入队
bool EnQueue(SqQueue &Q, int x)
{
    // 牺牲一个存储单元 判断是否已满
    if ((Q.rear + 1) % MaxSize == Q.front) //队列满
        return false;
    Q.data[Q.rear] = x;              //将x插入队尾
    Q.rear = (Q.rear + 1) % MaxSize; //9+1%10=0 实现循环队列
    return true;
}
// !!!队列元素个数 (rear+MaxSize-front)%MaxSize
// 出队
bool DeQueue(SqQueue &Q, int &x)
{
    // 对空
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; //指针后移 逻辑删除 指针不后移可返回队头元素
    return true;
}

int main()
{
    return 0;
}