/* 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
 * 
 * 2. *Реализовать шейкерную сортировку.
 * 
 * 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
 *
 * 4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
 *
 * 5** Сортировку вставками используя бинарный поиск.
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
        printf("Третье домашнеезадание.\n"\
            "Нажмите для запуска:\n"\
            "0 - выход;\n"\
            "1 - тест сортировок;\n"\
            "2 - тест бинарного (двоичного) поиска;\n");
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

void TestSort()
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
