/* 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <locale.h>
#include "stack.h"


int main()
{
    int flag = 1, x;
    setlocale(LC_ALL, "Russian");


    do
    {
        printf("Menu:\n" \
            "0 - exit;\n" \
            "1 - From ten number to two number.\n" \
            "\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            printf("Enter number:\n");
            scanf("%d", &x);
            printf("%d\n\n", TenToTwo(x));
            break;
        default:
            break;
        }
    } while (flag);

    /*system("pause");*/
    return 0;
}

int TenToTwo(int number)
{
    int i;
    STACK S;
    S.Top = NULL;

    while (number > 0)
    {
        if (!Push(&S, number % 2))
            return 0;
        number >>= 1;
    }

    while (Pop(&S, &i))
        number = number * 10 + i;
    return number;
}
