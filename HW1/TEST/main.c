#define _CRT_SECURE_NO_WARNINGS
//#include "Main.h"
#include <stdio.h>
#include <locale.h>

void Swap2(int *x, int *y);

void Swap2(int *x, int *y)
{
    //setlocale(LC_ALL, "Russian");

    *x ^= *y;
    wprintf(L"������� ������ x = %p �������� x = %d  ������� ������ y = %p �������� y = %d \n", x, *x, y, *y);
    *y ^= *x;
    wprintf(L"������� ������ x = %p �������� x = %d  ������� ������ y = %p �������� y = %d \n", x, *x, y, *y);
    *x ^= *y;
    wprintf(L"������� ������ x = %p �������� x = %d  ������� ������ y = %p �������� y = %d \n", x, *x, y, *y);
}

void Swap3(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int x = 10, y = 30;
    int *p, *c;
    p = &x;
    c = &y;
    wprintf(L"�������  x = %d y=%d \n", x, y);
    Swap2(&x, &y);
    wprintf(L"�������  �������� x = %d y = %d \n", x, y);
    wprintf(L"�������  �������� p = %d c = %d \n", x, y);
    wprintf(L"�������  ������ x = %p y = %p \n", &x, &y);
    wprintf(L"�������  ������ p = %p c = %p \n", &p, &c);
    getchar();
    return 0;
}
