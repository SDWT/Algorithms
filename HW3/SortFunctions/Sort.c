
#include "Sort.h"

int cnt;

/*Левый Бинарный поиск*/
int BinSearch(int *a, int N, int elem)
{
    int l = 0, r = N, m;

    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (a[m] == elem)
            return m;
        else if (a[m] < elem)
            l = m;
        else
            r = m;
    }

    return l;
}

/*Правый Бинарный поиск*/
int BinSearchRight(int *a, int N, int elem)
{
    int l = -1, r = N - 1, m;

    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (a[m] == elem)
            return m;
        else if (a[m] > elem)
            r = m;
        else
            l = m;
    }

    return r;
}

/*Функция запуска сортировки с проверкой*/
long StartSort(int *mas, int N, int(*Sort)(int *, int))
{
    int i, k;
    long startTime, endTime;

    srand(30);
    for (i = 0; i < N; i++)
    {
        mas[i] = rand();
        /*printf("%d ", mas[i]);*/
    }
    /*printf("\n\n");*/

    cnt = 0;
    startTime = clock();
    k = Sort(mas, N);
    endTime = clock();
    /*
    for (i = 0; i < 10; i++)
        printf("%d ", mas[i]);
    printf("\n\n");
    */
    return endTime - startTime;
}

/*обмен значений*/
void Swap(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
    /*cnt++;*/
}

/*Пузырьковая сортировка (Bubble) O(N^2)*/
int BubbleSort(int *a, int N)
{
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N - 1; j++)
            if (a[j] > a[j + 1])
                Swap(&a[j], &a[j + 1]);

    return cnt;
}

/* Ускоренная Пузырьковая сортировка (Bubble) O(N^2)*/
int FastBubbleSort(int *a, int N)
{
    int i, j, flag = 1;

    for (i = 0; 2 * i < N && flag; i++)
    {
        flag = 0;
        for (j = 0; j < N - 1; j++)
            if (a[j] > a[j + 1])
                Swap(&a[j], &a[j + 1]), flag = 1;
    }
    return cnt;
}

/*Шейкерная сортировка O(N ^ 2)*/
int ShackerSort(int *a, int N)
{
    int i, j, flag = 1;

    for (i = 0; i < N && flag; i++)
    {
        flag = 0;
        for (j = 0; j < N - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        for (j -= 2; j >= i; j--)
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                flag = 1;
            }
    }

    return cnt;
}

/*Сортировка методом выбора O(N ^ 2)*/
int SelectionSort(int *a, int N)
{
    int i, j, jMn;
    
    for (i = 0; i < N - 1; i++)
    {
        jMn = i;
        for (j = i + 1; j < N; j++)
            if (a[jMn] > a[j])
                jMn = j;
        Swap(&a[jMn], &a[i]);
    }

    return cnt;
}

/*Сортировка вставками O(N ^ 2)*/
int InsertionSort(int *a, int N)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = a[i];
        j = i;
        while (j > 0 && temp < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
            /*cnt++;*/
        }
        a[j] = temp;
        /*cnt++;*/
    }

    return cnt;
}

/*Сортировка вставками с бин поиском O(N*log(N)) / O(N*N)*/
int BinSearchInsertionSort(int *a, int N)
{
    int i, j, temp, r;

    for (i = 1; i < N; i++)
    {
        temp = a[i];
        j = i;
        r = BinSearchRight(a, i + 1, temp);

        /*
        for (j = 0; j < 10; j++)
            printf("%d ", a[j]);
        printf("\n\n");
        */
        for (j = i; j > r; j--)
            a[j] = a[j - 1];

        a[j] = temp;
        /*
        for (j = 0; j < 10; j++)
            printf("%d ", a[j]);
        printf("\n\n");
        */
    }
    return cnt;
}

int Sort(int *a, int N)
{
    //int i, j;

    return cnt;
}

