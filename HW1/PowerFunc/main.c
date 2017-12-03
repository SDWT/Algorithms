/* Реализовать алгоритм ускоренного возведения в степень.
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

__int64 QuickPow(__int64 a, __int64 b)
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

int main()
{
    __int64 x, step;

    setlocale(LC_ALL, "Russian");

    printf("Введите чсило и степень, в которую его возвести.\nЧисло: ");
    scanf("%lld", &x);
    printf("Степень: ");
    scanf("%lld", &step);
    printf("Число: %lld;\nСтепень: %lld;\nЗначение: %lld;\n", x, step, QuickPow(x, step));

    PauseMy();
    return 0;
}
