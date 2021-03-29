#include <stdio.h>
// 建立大根堆 根>=左右孩  根结点比孩子大
// len元素长度 len/2有分支节点个数 从后往前
// 理解下坠过程！

/////////////

// 堆的插入和删除
// 堆的插入不断和父节点i/2UP 比较替换 "上升过程"
// 堆的删除 删除后用栈底元素替换 之后 "下坠过程"

/////////////
void BuildMaxHeap(int A[], int len)
{
    void HeadAdjust(int A[], int k, int len);

    //len也代表元素初始位置（下标)
    for (int i = len / 2; i > 0; i--)
    {
        HeadAdjust(A, i, len); //调整所有非终端结点
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// 小根堆关键点
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k]; //A[0]存储当前根
    // i=2*k 指向当前左孩子 i<=len有孩子结点
    // 下坠过程↓↓↓
    for (int i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && A[i] > A[i + 1])
            i++; //判断左右孩子哪个更小
        if (A[0] <= A[i])
            break; //根若大于最大的孩子 则退出
        else
        {
            A[k] = A[i]; //根放最大的孩子
            k = i;       //指针指向到原来最大的孩子
        }
    }
    A[k] = A[0]; //放入根
}

// 基于大根堆 选择排序
// 堆底堆顶互换排除  不断成堆

void HeapSort(int A[], int len)
{
    void BuildMaxHeap(int A[], int len);

    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--)
    {
        swap(A[i], A[1]);        //堆底堆顶互换
        HeadAdjust(A, 1, i - 1); //i-1 n-1一趟交换
    }
}

int main()
{
    int a[10] = {'\0', 9, 8, 7, 3, 7, 1};
    HeapSort(a, 6);
    for (int i = 1; i <= 6; i++)
    {
        printf("%d ", a[i]);
    }
}