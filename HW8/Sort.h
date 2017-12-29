#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

/*Левый Бинарный поиск*/
int BinSearch(int *a, int N, int elem);

/*Правый Бинарный поиск*/
int BinSearchRight(int *a, int N, int elem);

/*Функция запуска сортировки с проверкой*/
long StartSort(int *mas, int N, int(*Sort)(int *, int));

/*обмен значений*/
void Swap(int *x, int *y);

/*Пузырьковая сортировка (Bubble) O(N^2)*/
int BubbleSort(int *a, int N);

/* Ускоренная Пузырьковая сортировка (Bubble) O(N^2)*/
int FastBubbleSort(int *a, int N);

/*Шейкерная сортировка O(N ^ 2)*/
int ShackerSort(int *a, int N);

/*Сортировка методом выбора O(N ^ 2)*/
int SelectionSort(int *a, int N);

/*Сортировка вставками O(N ^ 2)*/
int InsertionSort(int *a, int N);

/*Сортировка вставками с бин поиском O(N*log(N)) / O(N*N)*/
int BinSearchInsertionSort(int *a, int N);


/*Сложные сортировки*/
/*Функция запуска сложной сортировки с проверкой*/
long StartHardSort(int *mas, int N, int(*Sort)(int *, int));

/*Сортировка подсчётом*/
int CountingSort(int *a, int N);

