#include <stdio.h>
#include <stdlib.h>

long long int jie(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * jie(n - 1);
}
int main()
{
    int n;
    long long int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= 20; i++)
    {
        sum += jie(i);
        printf("{%d}阶乘为%lld \n", i, jie(i));
    }
    printf("%lld ", sum);

    return 0;
}