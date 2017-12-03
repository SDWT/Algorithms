/* *Автоморфные числа. Натуральное число называется автоморфным, если оно равно
 * последним цифрам своего квадрата. Например, 252 = 625.
 * Напишите программу, которая вводит натуральное число N и выводит на экран
 * все автоморфные числа, не превосходящие N.
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>


#define TRUE_MY 1
#define FALSE_MY 1

void PauseMy()
{
    char x;
    printf("Для выхода нажмите любую клавишу...\n");
    x = getchar();
}


int main()
{
    __int64 n, i, checker = 10;
    FILE *fout;

    if ((fout = fopen("Out.txt", "wt")) == NULL)
        return 0;

    setlocale(LC_ALL, "Russian");

    printf("Введите число, до которого искать Автоморфные числа\n");
    scanf("%lld", &n);

    for (i = 1; i <= n; i++)
    {
        if (i >= checker)
            checker *= 10;

        if ((i * (i - 1)) < 0 || checker < 0)
        {
            printf("End of numbers: %lld\n", i);
            fprintf(fout, "End of numbers: %lld\n", i);
            break;
        }

        if ((i * (i - 1)) % checker == 0)
        {
            printf("%19lld %19lld\n", i, i * i);
            fprintf(fout, "%19lld %19lld\n", i, i * i);
        }
    }

    fclose(fout);
    PauseMy();
    return 0;
}
