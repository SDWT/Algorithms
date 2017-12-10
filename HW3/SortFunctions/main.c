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

void TestBinSearch();
void TestSort();

int main()
{
    int flag = 1;

    setlocale(LC_ALL, "Russian");

    do
    {
        printf("������ ���������������.\n"\
            "������� ��� �������:\n"\
            "0 - �����;\n"\
            "1 - ���� ����������;\n"\
            "2 - ���� ��������� (���������) ������;\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            TestSort();
            break;
        case '2':
            TestBinSearch();
            break;
        case '3':
            flag = 0;
            break;
        default:
            break;
        }
    } while (flag);

    system("pause");
    return 0;
}

void TestBinSearch()
{
    int i, id, elem1 = 357, elem2 = 3435, n = 10;

    srand(30);
    
    printf("��� ����������� ������������� ��� �����.\n");
    printf("������� ���������� ��������� � ������� (0 < && <= 1000): ");
    scanf("%d", &n);

    if (n <= 0)
        n = 10;
    if (n > 1000)
        n = 1000;

    for (i = 0; i < n; i++)
        mas[i] = rand();
    InsertionSort(mas, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n\n");

    printf("������� 1-�� ������� ��� ������: ");
    scanf("%d", &elem1);

    printf("������� 2-�� ������� ��� ������: ");
    scanf("%d", &elem2);



    id = BinSearch(mas, n, elem1);
    printf("������� - %d, ����� � ������� - %d, ������� � ������� - %d\n", elem1, id, mas[id]);
    id = BinSearch(mas, n, elem2);
    printf("������� - %d, ����� � ������� - %d, ������� � ������� - %d\n", elem2, id, mas[id]);
}

void TestSort()
{
    int i, cntMin, cntMax, dx;

    printf("������� ����������� ���������� ��������� (> 0): ");
    scanf("%d", &cntMin);
    printf("������� ������������ ���������� ��������� (min < && <= 1 000 000): ");
    scanf("%d", &cntMax);
    printf("������� ��� ��������� (> 0): ");
    scanf("%d", &dx);

    if (dx < 0)
        dx *= -1;
    else if (dx == 0)
        dx = 1000000;

    if (cntMin < 0)
        cntMin *= -1;
    else if (cntMin == 0)
        cntMin = 100;

    if (cntMax < cntMin)
        cntMax += cntMin;
    if (cntMax > 1000000)
        cntMax = 1000000;

    printf("�� %d �� %d � ����� %d.\n", cntMin, cntMax, dx);

    for (i = cntMin; i <= cntMax; i += dx)
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
}
