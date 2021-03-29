#include <stdio.h>
#include <math.h>

void changeLitter(char &a)
{
    if (a >= 65 && a <= 97)
        a += 32;
    else
        a -= 32;
}
float getS(double a, double b, double c)
{
    double s, area;
    s = (a + b + c) / 2.0;
    double temp = s * (s - a) * (s - b) * (s - c);
    area = pow(temp, 0.5);
    return area;
}
int gcd1(int a, int b)
{
    int temp;
    if (a == 0 || b == 0)
        return 0;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }              //求最小值最大值，大的用a表示，小的用b表示
    while (b != 0) //用循环求最大公约数
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a; //返回最大公约数
}
int main()
{
    int a = 1;
    int b = 10;
    do
    {
        b -= a;
        a++;
    } while (b-- < 0);
    printf("%d\n", b);
    return 0;
}