#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} sqlist;

bool initList(sqlist L)
{
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
    return true;
}

int insertElem(sqlist L, int k, ElemType e)
{
    if (k < 1 || k > L.length)
    {
        return false;
    }
    for (int i = L.length - 1; i >= k; i--)
    {
        L.data[i + 1] = L.data[i];
    }
    L.data[k - 1] = e;
    return true;
}

int deleteElem(sqlist L, int k)
{
    ElemType e;
    e = L.data[k - 1];
    if (k < 1 || k > L.length)
    {
        return false;
    }
    for (int i = k - 1; k < L.length; i++)
        L.data[i] = L.data[i + 1];
    return e;
}
// 按值
int locateList(sqlist L, int k)
{
    return L.data[k - 1];
}