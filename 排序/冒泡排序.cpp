#include <stdio.h>
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// 有序 O(n) 无序O(n)
// 适用于链表 更大的冒泡
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {                      //i前的有序
        bool flag = false; //设置交换flag 不交换就跳
        for (int j = n - 1; j > i; j--)
        { //冒泡排序
            if (a[j - 1] > a[j])
            { //需要交换
                swap(a[j - 1], a[j]);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

/////////////////////////////////////////////////////////
void BubbleSortTest(int a[], int n)
{
    int j, k;
    for (j = 0; j < n - 1; j++)
    {
        bool flag = false;
        for (k = n - 1; k > j; k--)
        {
            if (a[k - 1] > a[k])
            {
                swap(a[k - 1], a[k]);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

void BubbleSortTest2(int a[], int n)
{
    int j, k;
    for (j = 0; j < n - 1; j++)
    {
        bool flag = false;

        for (k = n - 1; k > j; k--)
        {
            if (a[k] < a[k - 1])
            {
                swap(a[k], a[k - 1]);
                flag = true;
            }
        }
    }
}

/////////////////////////////////////////////////////////

int main()
{
    int a[10] = {9, 8, 7, 3, 5, 1};
    BubbleSortTest2(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}