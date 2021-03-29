#include <stdio.h>
#include <stdlib.h>

// 归并 把两个或多个有序序列合并成一个
int *B = (int *)malloc(10 * sizeof(int));
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; //将A中元素复制到B

    // 归并 i和j是B组分别指向2个序列头 k是A组指向小元素存储的位置
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    // 2个while循环检查i和j B组连个序列是否合并完 不需要排序的都顺序排序到A组
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {                                //切分
        int mid = (low + high) / 2;  //中间划分
        MergeSort(A, low, mid);      //左半部分归并排序
        MergeSort(A, mid + 1, high); //对右部分归并排序
        Merge(A, low, mid, high);    //归并
    }
}
int main()
{
    int a[10] = {9, 8, 7, 3, 7, 1};
    MergeSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}