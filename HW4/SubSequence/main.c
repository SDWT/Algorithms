/* *Решить задачу о нахождении длины максимальной последовательности с помощью
 * матрицы.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define TRUE_MY 1
#define FALSE_MY 1

int MaxSubSequence(char *s1, char *s2);

int main()
{
    //int m, n;
    char str1[1000], str2[1000];


    setlocale(LC_ALL, "Russian");

    printf("Введите строку 1:\n");
    scanf("%s", str1);
    printf("Введите строку 2:\n");
    scanf("%s", str2);
    printf("Длина максимальной последовательности: %d\n", MaxSubSequence(str1, str2));

    /*printf("Длина максимальной последовательности: %d\n", MaxSubSequence("load", "mcdonalds"));*/

    /*system("pause");*/
    return 0;
}

int MaxSubSequence(char *s1, char *s2)
{
    int i, j, ls1 = strlen(s1) + 1, ls2 = strlen(s2) + 1;
    int *matr;
    /*int x, y;*/

    if ((matr = calloc(ls1 * ls2, sizeof(int))) == NULL)
        return -1;

    for (i = 1; i < ls1; i++)
    {
        for (j = 1; j < ls2; j++)
        {
            matr[j + i * ls2] = (matr[j - 1 + i * ls2] >
                matr[j + (i - 1) * ls2]) ? matr[j - 1 + i * ls2] :
                matr[j + (i - 1) * ls2];
            if (s1[i - 1] == s2[j - 1])
                matr[j + i * ls2] += 1;
        }
        /*
        printf("  ");
        for (y = 1; y < ls2; y++)
        {
            printf("%c ", s2[y - 1]);
        }
        printf("\n");

        for (x = 1; x < ls1; x++, printf("\n"))
        {
            printf("%c ", s1[x - 1]);
            for (y = 1; y < ls2; y++)
            {
                printf("%d ", matr[y + ls2 * x]);
            }
        }
        printf("\n");
        */
    }
    i = matr[ls2 * ls1 - 1];
    free(matr);
    return i;
}
