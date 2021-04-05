#include <stdio.h>

void BuildMaxHeap(int a[], int);
void HeadAdjust(int a[], int, int);

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void BuildMaxHeap(int a[], int len)
{
    for (int i = len / 2; i > 0; i--)
    { //从后一半往前遍历
        HeadAdjust(a, i, len);
    }
}

void HeadAdjust(int a[], int k, int len)
{
    // k 当前根
    a[0] = a[k];
    for (int i = 2 * k; i <= len; i *= 2)
    { //遍历左子树
        if (i < len && a[i] < a[i + 1])
            i++;
        if (a[0] >= a[i])
            break;
        else
        {
            a[k] = a[i]; //调换 下坠
            k = i;
        }
    }
    a[k] = a[0];
}
// 大根堆排序
// 将对顶放到堆底 排除堆底 重新建立大根堆 如此往复
// 最终递增序列 上小下大
void HeapSort(int a[], int len)
{
    BuildMaxHeap(a, len);
    for (int i = len; i > 1; i--)
    {
        swap(a[i], a[1]);
        HeadAdjust(a, 1, i - 1);
    }
}