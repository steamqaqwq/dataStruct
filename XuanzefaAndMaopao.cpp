// 选择法 依次比较 最小放前 拿1 和 2 3 4 5比
// 冒泡法 沉底法  依次比较 最大放后
#include <stdio.h>

/*
测试数据
1
2
3
45
62
0
99
77
22
11
*/
// 选择法
int _main()
{
    int i, j, k;
    int a[10];
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    // 外循环排列好数组每个元素
    for (i = 0; i <= 8; i++)
    {
        // 把最大值放到最后一个元素
        for (j = i + 1; j <= 9; j++)
        {
            k = a[i];
            if (a[i] < a[j])
            {
                a[i] = a[j];
                a[j] = k;
                printf("a[%d]=%d \n", i, a[i]);
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("NEWa[%d]=%d \n", i, a[i]);
    }
    return 0;
}

// 冒泡法
int main()
{
    int i, j, k;
    int a[10];
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    // 外循环排列好数组每个元素
    for (i = 0; i <= 8; i++)
    {
        // 把最大值放到最后一个元素
        for (j = 0; j <= 8 - i; j++)
        {
            k = a[j];
            // 大就向后移
            if (a[j] > a[j + 1])
            {
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("NEWa[%d]=%d \n", i, a[i]);
    }
    return 0;
}
