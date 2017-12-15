/* 3. *Требуется обойти конём шахматную доску размером NxM, пройдя через все
 * поля доски по одному разу. Здесь алгоритм решения такой же, как и в задаче
 * о 8 ферзях. Разница только в проверке положения коня.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define TRUE_MY 1
#define FALSE_MY 0

int HorseStep(int N, int M, int i, int j, int di, int dj);
int HorseStart(int n, int m);
int HorseRec(int *a, int n, int m, int i, int j, int level);

int main()
{
    int m, n;

    setlocale(LC_ALL, "Russian");

    printf("Введите длину и высоту:\n");
    scanf("%d%d", &n, &m);
    
    /*
    printf("| %4cN%4c | %4cM%4c | %9c |\n", ' ', ' ', ' ', ' ', ' ');

    for (n = 1; n < 6; n++)
        for (m = 1; m < 6; m++)
            printf("| %9d | %9d | %9d |\n", n, m, HorseStart(n, m));
    */
    printf("Количество путей конём на доске %dx%d: %d\n", n, m, HorseStart(n, m));
    
    system("pause");
    return 0;
}

int HorseStart(int n, int m)
{
    int *mas, i, j, cnt = 0;

    if ((mas = calloc(m * n, sizeof(int))) == NULL)
        return -1;


    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            mas[j + m * i] = 1;
            cnt += HorseRec(mas, n, m, i, j, 2);
            mas[j + m * i] = 0;
        }

    free(mas);
    return cnt;
}


int HorseRec(int *a, int n, int m, int i, int j, int level)
{
    static int step[8][2] =
    {
        { -2, -1 },
    { -2, 1 },
    { 2, -1 },
    { 2, 1 },
    { -1, -2 },
    { 1, -2 },
    { -1, 2 },
    { 1, 2 }
    };
    int cnt = 0, k;
    /*int x, y;*/
    

    if (level >  n * m)
        return 1;

    for (k = 0; k < 8; k++)
        if (HorseStep(n, m, i, j, step[k][0], step[k][1]) && a[j + step[k][1] + m * (i + step[k][0])] == 0)
        {
            a[j + step[k][1] + m * (i + step[k][0])] = level;
            /*
            for (x = 0; x < n; x++, printf("\n"))
                for (y = 0; y < m; y++)
                {
                    printf("%d ", a[y + m * x]);
                }
            */
            cnt += HorseRec(a, n, m, i + step[k][0], j + step[k][1], level + 1);
            a[j + step[k][1] + m * (i + step[k][0])] = 0;
        }

    return cnt;
}

int HorseStep(int N, int M, int i, int j, int di, int dj)
{
    if (i + di < 0 || i + di >= N || j + dj < 0 || j + dj >= M)
        return FALSE_MY;
    return TRUE_MY;
}


