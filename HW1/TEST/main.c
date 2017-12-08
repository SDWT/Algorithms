#define _CRT_SECURE_NO_WARNINGS
//#include "Main.h"
#include <stdio.h>
#include <locale.h>

void Swap2(int *x, int *y);

void Swap2(int *x, int *y)
{
    //setlocale(LC_ALL, "Russian");

    *x ^= *y;
    wprintf(L"Выводим ссылку x = %p Значение x = %d  Выводим ссылку y = %p Значение y = %d \n", x, *x, y, *y);
    *y ^= *x;
    wprintf(L"Выводим ссылку x = %p Значение x = %d  Выводим ссылку y = %p Значение y = %d \n", x, *x, y, *y);
    *x ^= *y;
    wprintf(L"Выводим ссылку x = %p Значение x = %d  Выводим ссылку y = %p Значение y = %d \n", x, *x, y, *y);
}

void Swap3(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

int main()
{
    int x = 10, y = 30, i, j;
    int *p, *c;
    
    char str[] = "M          M          M          M          M   00     M          M" \
        "M          M          M          M          M]\\V\\\\1\\]0 M          M" \
        "M    `e    M    _e    M    eg    M    gg    MV\\~\\\\\\~\\\\VM    hg    M\n";
    
    setlocale(LC_ALL, "Russian");
    /*
    p = &x;
    c = &y;
    wprintf(L"Выводим  x = %d y=%d \n", x, y);
    Swap2(&x, &y);
    wprintf(L"Выводим  значения x = %d y = %d \n", x, y);
    wprintf(L"Выводим  значение p = %d c = %d \n", x, y);
    wprintf(L"Выводим  ссылку x = %p y = %p \n", &x, &y);
    wprintf(L"Выводим  ссылку p = %p c = %p \n", &p, &c);
    */
    /*printf("123 ");*/
    for (j = 0; j <= 47; j++)
    {
        for (i = 0; i < strlen(str); i++)
            /*if (str[i] == 77)
                printf("%c", '\n');
            else*/
            printf("%c", j + str[i]);
        printf("\n\n\n");
    }
    /*
    printf("%d ", '\n');
    printf("%d ", '\r');
    */

    /*printf("%c", 'a' + 13);*/
    getchar();
    return 0;
}
