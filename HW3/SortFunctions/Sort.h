#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int StartSort(int *mas, int N, int(*Sort)(int *, int));

/**/
void Swap(int *x, int *y);

/*����������� ���������� (Bubble) O(N^2)*/
int BubbleSort(int *a, int N);

/* ���������� ����������� ���������� (Bubble) O(N^2)*/
int FastBubbleSort(int *a, int N);

/*��������� ���������� O(N ^ 2)*/
int ShackerSort(int *a, int N);

/*���������� ������� ������ O(N ^ 2)*/
int SelectionSort(int *a, int N);

/*���������� ��������� O(N ^ 2)*/
int InsertionSort(int *a, int N);

/*���������� ��������� � ��� ������� O(N*log(N)) / O(N*N)*/
int BinSearchInsertionSort(int *a, int N);