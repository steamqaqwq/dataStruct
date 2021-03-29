#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define eq(A, B) (A == B)
typedef int ListItem; //表的元素类型
typedef ListItem *addr;
void ItemShow(ListItem x)
{
    printf("%d \n", x);
}
typedef struct alist
{
    ListItem *table; //表的数组
    int n, curr;     //n表长 curr 当前位置
    int maxsize;     //数组上限
} * List;
// 初�?�化ￄ1�7?
List ListInit(int size)
{
    List L = (List)malloc(sizeof *L);
    L->table = (ListItem *)malloc(size * sizeof(ListItem));
    L->maxsize = size;
    L->n = 0;
    return L;
}
// 清空ￄ1�7?
int ListEmpty(List L)
{
    return L->n == 0;
}
// 表L长度
int ListLength(List L)
{
    return L->n;
}
// 返回位序k处L的元ￄ1�7?
ListItem ListRetrieve(int k, List L)
{
    // k表示 位序
    if (k < 1 || k > L->n)
        exit(1);
    return L->table[k - 1];
}
// 返回元素x的位ￄ1�7?
int ListLocate(ListItem x, List L)
{
    for (int i = 0; i < L->n; i++)
    {
        if (L->table[i] == x)
        {
            return ++i;
        }
    }
    return 0;
}
// 表k处插ￄ1�7?x 返回布尔类型
int ListInsert(int k, ListItem x, List L)
{
    // 判断k值是否�?�合
    if (k < 1 || k > L->n)
    {
        return 1;
    }
    // 判断表满ￄ1�7?
    if (L->n == L->maxsize)
    {
        return 2;
    }
    for (int j = L->n; j >= k; j--)
    {
        L->table[j] = L->table[j - 1]; //后一位�??=前一ￄ1�7?
    }
    L->table[k - 1] = x;
    L->n++;
    return 3;
}
ListItem ListInsert2(int num, ListItem x, List L)
{
    // 判断k值
    if (num < 1 || num > L->n)
        return 1;
    //
}
ListItem ListDelete(int k, List L)
{
    if (k < 1 || k > L->n)
    {
        printf("aaaa");
        exit(1);
    }
    ListItem x = L->table[k - 1];
    for (int i = k; i < L->n; i++)
        L->table[i - 1] = L->table[i];
    L->n--;
    return x;
}
void PrintList(List L)
{
    for (int i = 0; i < L->n; i++)
    {
        ItemShow(L->table[i]);
    }
}
void ListFree(List L)
{
    free(L->table);
    free(L);
}
int main()
{
    List L = ListInit(10);
    for (int i = 0; i < MaxSize; i++)
    {
        L->table[i] = i + 1;
        L->n = MaxSize;
    }

    int a = 66;
    printf("元素插入状态 %d\n", ListInsert(1, a, L));
    printf("元素删除 %d\n", ListDelete(6, L));
    PrintList(L);
    ListFree(L);
    return 0;
}