/* ����������� �������� ����������� ���������� � �������.
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
    printf("��� ������ ������� ����� �������...\n");
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

    printf("������� ����� � �������, � ������� ��� ��������.\n�����: ");
    scanf("%lld", &x);
    printf("�������: ");
    scanf("%lld", &step);
    printf("�����: %lld;\n�������: %lld;\n��������: %lld;\n", x, step, QuickPow(x, step));

    PauseMy();
    return 0;
}
