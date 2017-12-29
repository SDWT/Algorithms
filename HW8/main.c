/* 1. Реализовать сортировку подсчетом.
 * 2. Реализовать быструю сортировку.
 * 3. *Реализовать сортировку слиянием.
 * 4. **Реализовать алгоритм сортировки со списком
 * 5. Проанализировать время работы каждого из вида сортировок для 100, 10000,
 *  1000000 элементов. Заполнить таблицу (см. методичку)
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
    printf("Третье домашнее задание.\n");
    do
    {
        printf("Нажмите для запуска:\n"\
            "0 - выход;\n"\
            "1 - тест сложных сортировок;\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            TestHardSort();
            break;
        case '2':
            //TestBinSearch();
            break;
        case '3':
            /*StartSort(mas, 10, BinSearchInsertionSort);*/

            break;
        default:
            break;
        }
    } while (flag);

    system("pause");
    return 0;
}

void TestBinSearch(void)
{
    int i, id, elem1 = 357, elem2 = 3435, n = 10;

    srand(30);
    
    printf("Вам представлен левосторонний бин поиск.\n");
    printf("Введите количество элементов в массиве (0 < && <= 1000): ");
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

    printf("Введите 1-ый элемент для поиска: ");
    scanf("%d", &elem1);

    printf("Введите 2-ой элемент для поиска: ");
    scanf("%d", &elem2);



    id = BinSearch(mas, n, elem1);
    printf("Элемент - %d, номер в массиве - %d, элемент в массиве - %d\n", elem1, id, mas[id]);
    id = BinSearch(mas, n, elem2);
    printf("Элемент - %d, номер в массиве - %d, элемент в массиве - %d\n", elem2, id, mas[id]);
}

void TestSortPrint(int cnt, char *name, double timeS)
{

    printf("|  %7d  |  %11s  |  %02d:%02d:%02d.%03d  |\n", cnt, name, (int)(timeS / 3600), ((int)timeS % 3600) / 60, ((int)timeS % 60), (int)(timeS * 1000) % 1000);
}

void TestHardSort(void)
{
    int i;
    int a[] = {100, 10000, 1000000};


    for (i = 0; i < 3; i++)
    {
        printf("|     N     |      Name     |  hh:mm:ss.ms   |\n");
        TestSortPrint(i, "Counting   ", StartHardSort(mas, a[i], CountingSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "Quick      ", StartHardSort(mas, a[i], CountingSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "Merge      ", StartHardSort(mas, a[i], CountingSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "ListConting", StartHardSort(mas, a[i], CountingSort) / (double)CLOCKS_PER_SEC);


        /*TestSortPrint(i, "Bubble     ", StartSort(mas, a[i], BubbleSort) / (double)CLOCKS_PER_SEC);            */
        /*TestSortPrint(i, "Fast Bubble", StartSort(mas, a[i], FastBubbleSort) / (double)CLOCKS_PER_SEC);        */
        /*TestSortPrint(i, "Shacker    ", StartSort(mas, a[i], ShackerSort) / (double)CLOCKS_PER_SEC);           */
        /*TestSortPrint(i, "Selection  ", StartSort(mas, a[i], SelectionSort) / (double)CLOCKS_PER_SEC);         */
        /*TestSortPrint(i, "Insertion  ", StartSort(mas, a[i], InsertionSort) / (double)CLOCKS_PER_SEC);         */
        /*TestSortPrint(i, "BSInsertion", StartSort(mas, a[i], BinSearchInsertionSort) / (double)CLOCKS_PER_SEC);*/
        printf("|___________|_______________|________________|\n");
    }
}

void TestSort(void)
{
    int i, cntMin, cntMax, dx;

    printf("Введите минимальное количество элементов (> 0): ");
    scanf("%d", &cntMin);
    printf("Введите максимальное количество элементов (min < && <= 1 000 000): ");
    scanf("%d", &cntMax);
    printf("Введите шаг элементов (> 0): ");
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

    printf("От %d до %d с шагом %d.\n", cntMin, cntMax, dx);

    for (i = cntMin; i <= cntMax; i += dx)
    {
        printf("|     N     |      Name     |  hh:mm:ss.ms   |\n");

        TestSortPrint(i, "Bubble     ", StartSort(mas, i, BubbleSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "Fast Bubble", StartSort(mas, i, FastBubbleSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "Shacker    ", StartSort(mas, i, ShackerSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "Selection  ", StartSort(mas, i, SelectionSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "Insertion  ", StartSort(mas, i, InsertionSort) / (double)CLOCKS_PER_SEC);
        TestSortPrint(i, "BSInsertion", StartSort(mas, i, BinSearchInsertionSort) / (double)CLOCKS_PER_SEC);

        /*printf("%10d |      Name      | %9d |\n", i, );*/
        /*
        printf("|  %7d  |  Bubble       | %9lf |\n", i, StartSort(mas, i, BubbleSort) / (double)CLOCKS_PER_SEC);
        printf("|  %7d  |  Fast Bubble  | %9lf |\n", i, StartSort(mas, i, FastBubbleSort) / (double)CLOCKS_PER_SEC);
        printf("|  %7d  |  Shacker      | %9lf |\n", i, StartSort(mas, i, ShackerSort) / (double)CLOCKS_PER_SEC);
        printf("|  %7d  |  Selection    | %9lf |\n", i, StartSort(mas, i, SelectionSort) / (double)CLOCKS_PER_SEC);
        printf("|  %7d  |  Insertion    | %9lf |\n", i, StartSort(mas, i, InsertionSort) / (double)CLOCKS_PER_SEC);
        printf("|  %7d  |  BSInsertion  | %9lf |\n", i, StartSort(mas, i, BinSearchInsertionSort) / (double)CLOCKS_PER_SEC);
        */
        printf("|___________|_______________|________________|\n");
    }
}

