#include <stdio.h>
#include <string.h>
/*
TEST Data
I am xxu 
*/
int main()
{
    char str[81];
    int count = 0;
    gets(str);
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     if (str[i] != ' ' && str[i] != '\0')
    //     {
    //         count++;
    //     }
    // }
    int j = 0;
    do
    {
        if (str[j] != ' ' && str[j] != '\0')
        {
            count++;
        }
    } while (str[j++] != '\0');
    printf("%d 个字符", count);
    return 0;
}