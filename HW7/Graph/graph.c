#include "graph.h"

int LoadGraph(GRAPH *Gr, char *filename)
{
    int n, m, i, j;
    FILE *Fin;

    if ((Fin = fopen(filename, "rt")) == NULL)
        return 0;

    fscanf(Fin, "%d", &n);

    if (n < 0 || n > 999)
    {
        return 0;
    }

    Gr->cntVertex = n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(Fin, "%d", &Gr->data[i][j]);
        }
    }

    return 1;
}

void PrintGraph(GRAPH *Gr)
{
    int i, j;
    printf("%d\n", Gr->cntVertex);

    for (i = 0; i < Gr->cntVertex; i++)
    {
        for (j = 0; j < Gr->cntVertex; j++)
        {
            printf("%d ", Gr->data[i][j]);
        }
        printf("\n");
    }

    return;
}

void dfs(GRAPH *Gr, int vertex)
{
    int i;
    Gr->used[vertex] = 1;

    for (i = 0; i < Gr->cntVertex; i++)
        if (Gr->used[i] != 0 && Gr->data[vertex][i] > 0)
            dfs(Gr, i);
        
    Gr->used[i] = 0;
}

int bfs(GRAPH *Gr, int vertex)
{
    int vrtx, i;
    Gr->queue.Head = Gr->queue.Tail = NULL;
    Gr->used[vertex] = 1;
    if (!Put(&Gr->queue, vertex))
        return 0;

    while (Get(&Gr->queue, &vrtx))
    {
        for (i = 0; i < Gr->cntVertex; i++)
            if (Gr->used[i] != 0 && Gr->data[vertex][i] > 0)
            {
                if (!Put(&Gr->queue, vertex))
                    return 0;
                Gr->used[vertex] = 1;
            }
    }

    for (i = 0; i < Gr->cntVertex; i++)
        Gr->used[vertex] = 0;
    while (Get(&(Gr->queue), NULL))
        ;

    return 1;
}

/*
int FPrintGraph(int **matrix, char *filename)
{
    int n, m, i, j;
    FILE *Fout;

    if ((Fout = fopen(filename, "wt")) == NULL)
        return 0;

    fprintf(Fout, "%d%d", &n, &m);

    if (m < 0 || n < 0 || m > 999 || n > 999)
    {
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            fprintf(Fout, "%d", &matrix[i][j]);
        }
    }

    return 1;
}
*/

