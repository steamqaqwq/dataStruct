#include <stdio.h>
// 算法思想:每次将一个待排序的记录按关键字大小插入到前面以排好序的子序列中，
// 直到全部记录插入完毕
// 大的往后推 判后小于前 就要一直往前比较
// 不带哨兵
void InsertSort(int a[], int n)
{ //a数组 n数组长度
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        { //后一项小于前一项
            temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--) //检查前面排序元素
            {
                a[j + 1] = a[j];
            }
            // j<0
            a[j + 1] = temp;
        }
    }
}

int main()
{
    int a[10] = {9, 8, 7, 3, 5, 1};
    InsertSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}