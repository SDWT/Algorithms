/* 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран
 * 2. Написать рекурсивную функцию обхода графа в глубину.
 * 3. Написать функцию обхода графа в ширину.
 * 4. *Создать библиотеку функций для работы с графами.
 *
 * Samsonov Dmitriy
 */

#include "graph.h"


GRAPH Gr;

void GetStr(char *str, int n);

int main()
{
    
    LoadGraph(&Gr, "graph.txt");
    
    printf("Cnt of vertex %d\n", Gr.cntVertex);
    
    PrintGraph(&Gr);

    /*system("pause");*/
    return 0;
}

void GetStr(char *str, int n)
{
    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && i < n - 1)
    {
        str[i++] = c;
    }
    str[n - 1] = 0;
}
