#include <stdio.h>
#include <stdlib.h>
#define initSize 10
typedef int ElemType;

// 静态数组
typedef struct
{
    ElemType *data; //动态数组
    ElemType length;
    int MaxSize;

} sqlist;
void initList2(sqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

void initList(sqlist &L)
{
    L.data = (int *)malloc(initSize * sizeof(int));
    L.length = 0;
    L.MaxSize = initSize;
}
// 插入操作 按位序插入
bool insertElem(sqlist &L, int p, ElemType e)
{
    int i;
    if (p < 1 || p > L.length || L.length == L.MaxSize)
        return false;

    for (i = L.length; i >= p; i--) //i向后遍历直到 = p
    {
        L.data[i] = L.data[i - 1]; //后移动
    }
    L.data[p - 1] = e;
    L.length--;
}
void IncreaseSize(sqlist &L, int len)
{
    int *p = L.data; //临时存放数据
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
int main()
{
    sqlist L;
    initList(L);
    for (int i = 0; i < 5; i++)
        L.data[i] = i;
    L.length = 0;
    IncreaseSize(L, 10);
    return 0;
}