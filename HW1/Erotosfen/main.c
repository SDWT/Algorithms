/* Реализовать алгоритм поиска простых чисел “Решето Эратосфена”.
 * *Вывести самое большое число найденное с помощью этого алгоритма.
 * ***Рассчитайте время выполнения нахождения этого числа.
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


#define TRUE_MY 1
#define FALSE_MY 1
#define MAX_ELEMS 1000000000


char IsPrime[MAX_ELEMS];

void PauseMy()
{
    char x;
    printf("Для выхода нажмите любую клавишу...\n");
    x = getchar();
}

unsigned int Erotosfen(unsigned int n)
{
    unsigned int i, j, lastId;
    FILE *fout;

    for (i = 0; i <= n; i++)
    {
        IsPrime[i] = 1;
    }

    if ((fout = fopen("Primes.txt", "wt")) == NULL)
    {
        return -1;
    }


    for (i = 2; i <= n; i++)
    {
        if (IsPrime[i] == 0)
            continue;
        //printf("\r%10d", i);
        for (j = i * i; j > 0 && j <= n; j += i)
        {
            IsPrime[j] = 0;
        }
        fprintf(fout, "%d\n", i);
        lastId = i;
        /*if (i % 100 == 0)
            printf("\r%d", i);*/
    }
    fclose(fout);
    return lastId;
}

unsigned int main()
{
    /* 18 446 744 073 709 551 615
     * 18446744073709551615
     */
    unsigned int N = 4294967294UL;
    double dt, timeStart = (double)clock();
    int answer, h, m, s;
    FILE *fout;


    setlocale(LC_ALL, "Russian");

    answer = Erotosfen(MAX_ELEMS - 1);
    dt = (clock() - timeStart) / CLOCKS_PER_SEC;

    s = ((int)dt + 1) % 60;
    m = (int)(dt /= 60) % 60;
    h = (int)(dt /= 60);

    //printf("%d\n", Erotosfen(2000000000UL));
    printf("%d\n%d:%d:%d\n", answer, h, m, s);
    
    if ((fout = fopen("Primes.txt", "at")) == NULL)
        return 0;
    fprintf(fout, "%d\n%d:%d:%d\n", answer, h, m, s);

    fclose(fout);
    PauseMy();
    return 0;
}
