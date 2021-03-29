#include <stdio.h>
void swap(int *a, int *b);

void SimpleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(&a[i], &a[min]);
    }
}
int main()
{
    int a[10] = {9, 8, 7, 3, 5, 1};
    SimpleSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b)
{
    int *temp;
    temp = b;
    b = a;
    a = temp;
}