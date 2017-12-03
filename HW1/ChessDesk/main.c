/* *С клавиатуры вводятся числовые координаты двух полей шахматной доски
 *(x1, y1, x2, y2).Требуется определить, относятся ли к поля к одному цвету или
 *нет.
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int Chess(int x1, int y1, int x2, int y2);

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
    char x1, y1, x2, y2;
    char buf[100];

    setlocale(LC_ALL, "Russian");
    
    printf("Введите номера и буквы позиции клетки x: 1-8, y: a-f:\n");
    printf("x1 (1-8): ");
    scanf("%s", buf);
    x1 = buf[0];

    printf("y1 (a-f): ");
    scanf("%s", buf);
    y1 = buf[0];

    printf("x2 (1-8): ");
    scanf("%s", buf);
    x2 = buf[0];

    printf("y2 (a-f): ");
    scanf("%s", buf);
    y2 = buf[0];

    x1 -= '0';
    y1 -= 'a' - 1;
    x2 -= '0';
    y2 -= 'a' - 1;

    if (x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8 && x2 >= 1 && x2 <= 8 && y2 >= 1 && y2 <= 8)
        if (Chess(x1, y1, x2, y2))
            printf("Цвет клеток совпадает.\n");
        else
            printf("Цвет клеток не совпадает.\n");
    else
        printf("Ошибка: не корректные данные.\n");

    PauseMy();
    return 0;
}

int Chess(int x1, int y1, int x2, int y2)
{
    int a = (x1 + y1) % 2, b = (x2 + y2) % 2;
    if (a == b)
        return TRUE_MY;
    return FALSE_MY;
}

