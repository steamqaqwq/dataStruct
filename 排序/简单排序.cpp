#include <stdio.h>
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void simpleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) //外层不用扫最后一个 每次从哪开始扫
    {
        int min = i;
        for (int j = i + 1; j < n; j++) //交换需要比较最后一个
        {
            if (a[j] < a[min])
                min = j; //swap(a[i], a[min]);
        }
        if (min != i) //可删
            swap(a[i], a[min]);
    }
}
void spSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
}
int main()
{
    int a[10] = {9, 8, 7, 3, 7, 1};
    simpleSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}