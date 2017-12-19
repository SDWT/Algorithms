/* Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <locale.h>
#include "stack.h"


int main()
{
    int flag = 1;
    char str[1002];
    setlocale(LC_ALL, "Russian");


    do
    {
        printf("Menu:\n" \
            "0 - exit;\n" \
            "1 - show stack and queue;\n" \
            "\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            break;
        default:
            break;
        }
    } while (flag);

    /*system("pause");*/
    return 0;
}

