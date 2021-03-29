#include <stdio.h>
void InsertSort(int A[], int n)
{
    int i, j; //空间复杂度O(1) 时间复杂o(n) O(n^2)
    for (i = 2; i <= n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i]; //A[0]哨兵用来存temp
            for (j = i - 1; A[0] < A[j]; j--)
            { //
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0]; //复制到a[]
        }
    }
}

void InsertTest(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp; //此时j已经--
        }
    }
}

void InsertSort2(int a[], int n)
{
    // 带哨兵
    int j, k;
    for (j = 2; j <= n; j++)
    {
        if (a[j] < a[j - 1])
        {
            a[0] = a[j]; //temp 小
            for (k = j - 1; a[0] < a[k]; k--)
                a[k + 1] = a[k];
            a[k + 1] = a[0];
        }
    }
}
void InsertSort3(int a[], int n)
{
    //哨兵
    int j, k;
    for (j = 2; j <= n; j++)
    {
        if (a[j - 1] > a[j])
        {
            a[0] = a[j];
            for (k = j - 1; a[0] < a[k]; k--)
            {
                a[k + 1] = a[k];
            }
            a[k + 1] = a[0];
        }
    }
}
int main()
{
    int a[10] = {'\0', 9, 8, 7, 3, 5, 1};
    InsertSort3(a, 6);
    for (int i = 1; i <= 6; i++)
    {
        printf("%d ", a[i]);
    }
}