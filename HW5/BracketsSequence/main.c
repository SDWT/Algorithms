/* 3. Ќаписать программу, котора€ определ€ет, €вл€етс€ ли введенна€ скобочна€
 * последовательность правильной. ѕримеры правильных скобочных выражений: (),
 * ([])(), {}(), ([{}]), неправильных Ч )(, ())({), (, ])}), ([(]) дл€ скобок
 * [,(,{.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <locale.h>
#include "stack.h"


int CheckBracketSequance(char *str);

int main()
{
    int flag = 1;
    char str[1002];
    setlocale(LC_ALL, "Russian");


    do
    {
        printf("Menu:\n" \
            "0 - exit;\n" \
            "1 - check bracket sequence;\n" \
            "\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            printf("Enter bracket sequence (less 1000 symbols):\n");
            scanf("%s", str);
            if (CheckBracketSequance(str))
                printf("Correct bracket bracket sequence.\n\n");
            else
                printf("Not correct bracket sequence.\n\n");
            break;
        default:
            break;
        }
    } while (flag);

    /*system("pause");*/
    return 0;
}

int CheckBracketSequance(char *str)
{
    char prev = 0;
    int i = 0;
    STACK S;
    S.Top = NULL;

    while (str[i] != 0)
    {
        prev = 0;
        switch (str[i])
        {
        case '{':
        case '(':
        case '[':
            Push(&S, str[i]);
            break;
        case '}':
            if (!Pop(&S, &prev))
            {
                printf("Have not open bracket.\n");
                while (Pop(&S, NULL))
                    ;
                return 0;
            }

            if (prev != '{')
            {
                printf("Open elem: %c - Close elem: %c.\n", prev, str[i]);
                while (Pop(&S, NULL))
                    ;
                return 0;
            }
            break;
        case ']':
            if (!Pop(&S, &prev))
            {
                printf("Have not open bracket.\n");
                while (Pop(&S, NULL))
                    ;
                return 0;
            }

            if (prev != '[')
            {
                printf("Open elem: %c - Close elem: %c.\n", prev, str[i]);
                while (Pop(&S, NULL))
                    ;
                return 0;
            }
            break;
        case ')':
            if (!Pop(&S, &prev))
            {
                printf("Have not open bracket.\n");
                while (Pop(&S, NULL))
                    ;
                return 0;
            }

            if (prev != '(')
            {
                printf("Open elem: %c - Close elem: %c.\n", prev, str[i]);
                while (Pop(&S, NULL))
                    ;
                return 0;
            }
            break;
        default:
            printf("Error: sequence has another element^ %d.\n", str[i]);
            while (Pop(&S, NULL))
                ;
            return 0;
            break;
        }
        i++;
    }

    if (Pop(&S, NULL))
    {
        printf("Have not close barcket.\n");
        while (Pop(&S, NULL))
            ;
        return 0;
    }

    return 1;
}
