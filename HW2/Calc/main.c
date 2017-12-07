/* 3. Исполнитель Калькулятор преобразует целое число, записанное на экране.
 * У исполнителя две команды, каждой команде присвоен номер:
 *      1. Прибавь 1;
 *      2.Умножь на 2;
 * Первая команда увеличивает число на экране на 1, вторая увеличивает это
 * число в 2 раза. Сколько существует программ, которые число 3 преобразуют в
 * число 20?
 *      а) с использованием массива;
 *      б) с использованием рекурсии.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define TRUE_MY 1
#define FALSE_MY 1

int CalcRec(int cur, int first)
{
    /*int x = 0;*/

    if (cur < first)
        return 0;
    else if (cur == first)
        return 1;

    return CalcRec(cur - 1, first) + ((cur % 2) ? 0 : CalcRec(cur / 2, first));
    /*
    x = CalcRec(cur - 1, first) + ((cur % 2) ? 0 : CalcRec(cur / 2, first));
    printf("%d - %d %d\n", x, cur, first);
    return x;
    */
}

int CalcMass(int cur, int first)
{
    int i, *mas;
    if (cur < first)
        return 0;
    mas = (int *)malloc(cur - first + 1);

    mas[0] = 1;
    for (i = 1; i < first; i++)
    {
        mas[i] = mas[i - 1];
    }

    for (i = first; i <= cur - first; i++)
    {
        mas[i] = mas[i - 1] + (((i - first) % 2) ? 0 : mas[(i - first) / 2]);
    }

    return mas[i - 1];
}

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Решение через рекурсию %d;\nРешение через массив %d.\n", CalcRec(20, 3), CalcMass(20, 3));

    /*system("pause");*/
    return 0;
}
