#include <stdio.h>
void ShellSort(int a[], int n)
{
    int d, i, j;
    //a[0]暂存单元 j<=0时存放
    for (d = n / 2; d >= 1; d = d / 2) //增量
    {
        for (i = d + 1; i <= n; ++i)
        {
            if (a[i] < a[i - d])
            { //a[i]插入有序增量子表
                a[0] = a[i];
                for (j = i - d; j > 0 && a[0] < a[j]; j -= d)
                    a[j + d] = a[j]; //记录后移,查找插入位置
                a[j + d] = a[0];     //插入
            }
        }
    }
}
int main()
{
    int n1 = 3;
    int a[3] = {65, 49, 49};
    ShellSort(a, 3);
    for (int i = 1; i <= n1; i++)
    {
        printf("%d ", a[i]);
    }
}