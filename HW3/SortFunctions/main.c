/* 1. ����������� �������������� ����������� ����������. �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������. �������� ������� ����������, ������� ���������� ���������� ��������.
 * 
 * 2. *����������� ��������� ����������.
 * 
 * 3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������. ������� ���������� ������ ���������� �������� ��� -1, ���� ������� �� ������.
 *
 * 4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ��������������� ���������� ���������.
 *
 * 5** ���������� ��������� ��������� �������� �����.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS


#include "Sort.h"

#define TRUE_MY 1
#define FALSE_MY 1


int mas[1000005];



int main()
{
    int i;

    setlocale(LC_ALL, "Russian");
    /*
    printf("������� ����� � �������, � ������� ��� ��������.\n�����: ");
    scanf("%lld", &x);
    printf("�������: ");
    scanf("%lld", &step);
    */
    /*
    srand(30);
    for (i = 0; i < 10; i++)
    {
        mas[i] = rand();
        printf("%d ", mas[i]);
    }
    printf("\n\n");
    */
    for (i = 10000; i <= 100000; i += 10000)
    {
        printf("\n\n     N     |      Name     |    cnt    |\n");
        /*printf("%10d |      Name      | %9d |\n", i, );*/
        printf("%10d |  Bubble       | %9lf |\n", i, StartSort(mas, i, BubbleSort) / (double)CLOCKS_PER_SEC);
        printf("%10d |  Fast Bubble  | %9lf |\n", i, StartSort(mas, i, FastBubbleSort) / (double)CLOCKS_PER_SEC);
        printf("%10d |  Shacker      | %9lf |\n", i, StartSort(mas, i, ShackerSort) / (double)CLOCKS_PER_SEC);
        printf("%10d |  Selection    | %9lf |\n", i, StartSort(mas, i, SelectionSort) / (double)CLOCKS_PER_SEC);
        printf("%10d |  Insertion    | %9lf |\n", i, StartSort(mas, i, InsertionSort) / (double)CLOCKS_PER_SEC);
        /*printf("%10d |  BSInsertion  | %9d |\n", i, StartSort(mas, i, BinSearchInsertionSort));*/
    }

    system("pause");
    return 0;
}
