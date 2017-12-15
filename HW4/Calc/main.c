/* 4. ����������� ������ ����������� �� ��� � ������� ��������.
 *
 * 5. ����������� ������ ����������� �� ��� � ������� ��������.
 * �������� �� 1->16 ������ ����� 7, �� �� ������� ����� 9.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int Calc_1_16_7_9(void)
{
    /*int x = 0;*/
    /*
    int a, b, c, d;

    a = CalcRec(7, 1);
    b = CalcRec(16, 7);
    c = CalcRec(9, 7);
    d = CalcRec(16, 9);

    printf("%d %d %d %d\n", a, b, c, d);
    */
    return CalcRec(7, 1) * (CalcRec(16, 7) - CalcRec(9, 7) * CalcRec(16, 9));


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

    printf("������� ����� �������� %d;\n������� ����� ������ %d.\n", CalcRec(20, 3), CalcMass(20, 3));
    printf("������� ����� �������� 1->16 ������ ����� 7, �� �� ������� ����� 9  %d.\n", Calc_1_16_7_9());

    system("pause");
    return 0;
}
