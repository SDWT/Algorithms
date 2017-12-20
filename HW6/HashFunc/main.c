/* 6. ***Реализовать двухстороннюю очередь.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void strHash(char *str, char *hash);
void GetStr(char *str, int n);

int main()
{
    int flag = 1;
    char str[1005], hashStr[1005];
    setlocale(LC_ALL, "Russian");

    do
    {
        printf("Menu:\n" \
            "0 - exit;\n" \
            "1 - Hash function;\n" \
            "\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            printf("Enter string(less 1000 symbols):\n");
            /*scanf("%s\n", str);*/
            GetStr(str, 1000);
            strHash(str, hashStr);
            printf("Hash string: %s\n", hashStr);
            break;
        default:
            break;
        }
    } while (flag);

    /*system("pause");*/
    return 0;
}

void GetStr(char *str, int n)
{
    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && i < n - 1)
    {
        str[i++] = c;
    }
    str[n - 1] = 0;
}

void strHash(char *str, char *hash)
{
    int hs = 0, i = 0;

    while (str[i] != 0)
    {
        hs += str[i++];
    }

    sprintf(hash, "%x", hs);
}
