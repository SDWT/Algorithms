
#include "Sort.h"

int cnt;

/*����� �������� �����*/
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

/*������ �������� �����*/
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

/*������� ������� ���������� � ���������*/
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

/*������� ������� ������� ���������� � ���������*/
long StartHardSort(int *mas, int N, int(*Sort)(int *, int))
{
    int i, k;
    long startTime, endTime;

    srand(30);
    for (i = 0; i < N; i++)
    {
        mas[i] = rand() % 1000;
        /*printf("%d ", mas[i]);*/
    }
    /*printf("\n\n");*/

    cnt = 0;
    startTime = clock();
    k = Sort(mas, N);
    endTime = clock();
    /*
    for (i = 0; i < N; i++)
        printf("%d ", mas[i]);
    printf("\n\n");
    */
    return endTime - startTime;
}

/*����� ��������*/
void Swap(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
    /*cnt++;*/
}

/*����������� ���������� (Bubble) O(N^2)*/
int BubbleSort(int *a, int N)
{
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N - 1; j++)
            if (a[j] > a[j + 1])
                Swap(&a[j], &a[j + 1]);

    return cnt;
}

/* ���������� ����������� ���������� (Bubble) O(N^2)*/
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

/*��������� ���������� O(N ^ 2)*/
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

/*���������� ������� ������ O(N ^ 2)*/
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

/*���������� ��������� O(N ^ 2)*/
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

/*���������� ��������� � ��� ������� O(N*log(N)) / O(N*N)*/
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

/*������� ����������*/

/*���������� ���������*/
int CountingSort(int *a, int N)
{
    int i, j;
    int count[1000] = { 0 };

    if (N >= 1000)
        return -1;

    for (i = 0; i < N; i++)
    {
        count[a[i]]++;
    }

    j = 0;
    for (i = 0; i < 1000; i++)
    {
        while (count[i]-- > 0 && j < N)
        {
            a[j] = i;
            j++;
        }
    }

    return 0;
}

int CountingSort2(int *a, int N, int minEl, int maxEl)
{
    int i, j;
    int count[1000] = { 0 };

    if (maxEl - minEl + 1 > 1000)
        return -1;

    for (i = 0; i < N; i++)
    {
        count[a[i] - minEl]++;
    }

    j = 0;
    for (i = 0; i < maxEl - minEl; i++)
    {
        while (count[i] > 0)
        {
            a[j] = i + minEl;
            j++;
        }
    }

    return 0;
}

/*������� ����������*/
void MYqsort(int *a, int b, int e)
{
    int l = b, r = e, tmp;
    int chosenElement = a[(l + r) / 2];

    while (l <= r)
    {
        while (a[l] < chosenElement)
            l++;
        while (a[r] > chosenElement)
            r--;
        if (l <= r)
        {
            tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            l++, r--;
        }
    }
    if (b < r)
        MYqsort(a, b, r);
    if (e > l)
        MYqsort(a, l, e);
}

int QuickSort(int *a, int N)
{
    MYqsort(a, 0, N - 1);
    return 0;
}

/*���������� ��������*/
void Merge(int *a, int l, int r)
{
    int i = l, j = (l + r) / 2 + 1, k;
    int *buf = malloc(((r + l) / 2 - l + 1) * sizeof(int));

    for (i = l; i < j; i++)
    {
        buf[i - l] = a[i];
    }

    i = l;

    for (k = l; k <= r && j <= r && i <= (l + r) / 2; k++)
    {
        if (buf[i - l] < a[j])
        {
            a[k] = buf[i - l];
            i++;
        }
        else
            a[k] = a[j++];
    }

    while (i <= (l + r) / 2)
    {
        a[k++] = buf[i++ - l];
    }

    while (j <= r)
    {
        a[k++] = a[j++];
    }
    free(buf);
}

void MY_MergeSort(int *a, int l, int r)
{
    int tmp;
    
    if (r <= l)
        return;
    MY_MergeSort(a, l, (l + r) / 2);
    MY_MergeSort(a, (l + r) / 2 + 1, r);
    Merge(a, l, r);
}

int MergeSort(int *a, int N)
{
    MY_MergeSort(a, 0, N - 1);
    return 0;
}


/*�������� ���������� �� �������*/

