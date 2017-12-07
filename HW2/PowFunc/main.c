/* 2. Реализовать функцию возведения числа a в степень
 * a. без рекурсии;
 * b. рекурсивно;
 * c. *рекурсивно, используя свойство чётности степени.
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define TRUE_MY 1
#define FALSE_MY 1

 /* Функция быстрого ускорения через цикл */
__int64 QuickPowCircle(__int64 a, __int64 b)
{
  __int64 n  = 1;

  while (b)
  {
      if (b % 2)
      {
          b--;
          n *= a;
      }
      else
      {
          a *= a;
          b /= 2;
      }
  }

  return n;
}

/* Функция быстрого ускорения через рекурсию */
__int64 QuickPowRec(__int64 a, __int64 b)
{
    if (b <= 0)
        return 1;

    if (b % 2)
        return a * QuickPowRec(a, b - 1);
    else
        return QuickPowRec(a * a, b / 2);
}

int main()
{
    __int64 x, step;

    setlocale(LC_ALL, "Russian");

    printf("Введите чсило и степень, в которую его возвести.\nЧисло: ");
    scanf("%lld", &x);
    printf("Степень: ");
    scanf("%lld", &step);
    printf("Число: %lld;\nСтепень: %lld;\nЗначение: %lld;\n", x, step, QuickPowCircle(x, step));
    printf("Число: %lld;\nСтепень: %lld;\nЗначение: %lld;\n", x, step, QuickPowRec(x, step));

    system("pause");
    return 0;
}
