#include <stdio.h>
#define MaxSize 10
// 顺序栈 ≈顺序表
typedef struct
{
    int data[MaxSize];
    int top; //栈顶指针
} SqStack;

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true; //栈空
    else
        return false; //不空
}

void InitStack(SqStack &S)
{
    S.top = -1; //初始化栈顶指针为-1
}

//
bool Push(SqStack &S, int x)
{
    if (S.top == MaxSize - 1) //判断栈满
        return false;
    S.data[++S.top] = x; //栈顶指针初始化-1,需存入数据前+1变为下标
    return true;
}
//逻辑删除 top下移
bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false; //栈空
    // top-- 存入数据后 栈顶指针下移 逻辑删除栈顶元素
    x = S.data[S.top--]; //栈顶元素赋值给x
    return true;
}

// 读取栈顶元素
int GetTop(SqStack &S)
{
    if (S.top == -1)
        return false; //栈空
    return S.data[S.top];
}
////////////////////////////////
////另一种方式 top=0
////////////////////////////////

// 共享栈
// top0 0号栈栈顶指针 top1 1号栈栈顶指针
typedef struct
{
    int data[MaxSize];
    int top0;
    int top1;
} shStack;
// 栈满条件 top0+1 == top1
bool InitShStack(shStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;
    return true;
}
