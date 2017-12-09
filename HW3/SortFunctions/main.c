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



int main()
{
    int i;

    setlocale(LC_ALL, "Russian");
    /*
    printf("Введите чсило и степень, в которую его возвести.\nЧисло: ");
    scanf("%lld", &x);
    printf("Степень: ");
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
