#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "list.h"

#define MAX_GRAPH 1000

typedef struct tagGRAPH
{
    int data[MAX_GRAPH][MAX_GRAPH];
    int used[MAX_GRAPH];
    QUEUE queue;
    int cntVertex;

} GRAPH;

int LoadGraph(GRAPH *Gr, char *filename);
void PrintGraph(GRAPH *Gr);
void dfs(GRAPH *Gr, int vertex);
int bfs(GRAPH *Gr, int vertex);
