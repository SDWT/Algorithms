/* 1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>


#define TRUE_MY 1
#define FALSE_MY 1


void To2From10(int number);

int main()
{
    int isEnd = 1;
    int x = 0;

    setlocale(LC_ALL, "Russian");

    do
    {
        printf("������� ����� ������� 0.\n"\
            "��� ������ ������� 0.\n");
        scanf("%d", &x);
        To2From10(x);
        printf("\n");
    } while (x);

    system("pause");
    return 0;
}

void RecTo2From10(int number)
{
    if (number <= 0)
        return 0;
    RecTo2From10(number / 2);
    printf("%d", number % 2);
}

void To2From10(int number)
{
    if (number < 0)
    {
        printf("����� ������ ����.\n");
        return 0;
    }
    else if (number == 0)
    {
        printf("0");
    }
    RecTo2From10(number);
    printf("\n");
}
