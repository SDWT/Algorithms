#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int StartSort(int *mas, int N, int(*Sort)(int *, int));

/**/
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