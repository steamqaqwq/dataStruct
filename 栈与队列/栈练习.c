#include <stdio.h>
#define maxsize 10

// 顺序栈
typedef struct
{
    int data[maxsize];
    int top;
} sqStack;

int initStack(sqStack *st)
{
    st->data;
    st->top = -1;
    return 1;
}

int push(sqStack *st, int x)
{
    if (st->top == maxsize - 1)
        return 0;
    st->data[++st->top] = x;
    return 1;
}

int pop(sqStack *st, int *x)
{
    if (st->top == -1)
        return 0;
    *x = st->data[st->top--];
    return *x;
}

int main()
{
    sqStack a;
    int x;
    initStack(&a);
    push(&a, 1);
    push(&a, 2);
    pop(&a, &x);
    pop(&a, &x);
    printf("删除%d,%d\n", x, a.top);
    printf("%d\n", a.top);
    for (int i = 0; i < maxsize; i++)
    {
        printf("%d\n", a.data[i]);
    }
    return 0;
}