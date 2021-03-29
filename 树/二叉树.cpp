#include <stdio.h>
#include <math.h>
#define MaxSize 100
// 完全二叉树 顺序存储
struct TreeNode
{
    int value;
    bool isEmpty;
};
TreeNode t[MaxSize];
int main()
{
    // 初始化数组
    int n = 12;
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i].value = i;
        t[i].isEmpty = false;
    }
    // i左孩子 2i
    // i右孩子 2i+1
    // i的父节点 i/2
    // i所在的层次 高h-1<n<=h满二叉树
    // -> log2(n+1)↑  log2n↓+1
    for (int i = 1; i <= n; i++)
    {
        if ((2 * i + 1) <= n)
        {
            printf("{%d}有右孩子\n", t[i].value);
        }
        else if (2 * i <= n)
        {
            printf("{%d}有左孩子{%d}", t[i].value, t[2 * i].value);
            printf("\t父节点是%d", t[i / 2].value);
            printf("\t所在层次是%d\n", ((int)log2(i) + 1));
        }
    }
    return 0;
}