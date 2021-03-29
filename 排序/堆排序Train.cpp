#include <stdio.h>
#include <stdlib.h>

void BuildMaxHeap(int a[], int);
void HeadAdjust(int a[], int, int);

void swap(int &a, int &b);
void BuildMaxHeap(int a[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        HeadAdjust(a, i, len);
    }
}

void HeadAdjust(int a[], int k, int len)
{
    a[0] = a[k];
    for (int i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && a[i] < a[i + 1])
            i++;
        if (a[0] >= a[i])
            break;
        else
        {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}

void HeapSort(int a[], int len)
{
    BuildMaxHeap(a, len);
    for (int i = len; i > 1; i--)
    {
        swap(a[i], a[1]);
        HeadAdjust(a, 1, i - 1);
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
#define MaxSize 10
int *B = (int *)malloc(MaxSize * sizeof(int));
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while (i <= mid)
    {
        A[k++] = B[i++];
        while (j <= high)
        {
            A[k++] = B[j++];
        }
    }
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}
int main()
{
    int a[10] = {'\0', 9, 8, 7, 3, 7, 1};
    int b[10] = {22, 8, 7, 3, 2, 1};
    printf("堆排序\n");

    HeapSort(a, 6);
    for (int i = 1; i <= 6; i++)
    {
        printf("%d ", a[i]);
    }
    MergeSort(b, 0, 5);
    printf("\n归并排序\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}