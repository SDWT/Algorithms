/* 6. ***Реализовать двухстороннюю очередь.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <locale.h>
#include "list.h"

void ShowWork();
void CheckMemory();

int main()
{
    int flag = 1;
    setlocale(LC_ALL, "Russian");

    do
    {
        printf("Menu:\n" \
            "0 - exit;\n" \
            "1 - show dequeue;\n" \
            "\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            /*ShowWork();*/
            break;
        default:
            break;
        }
    } while (flag);

    /*system("pause");*/
    return 0;
}

void ShowWork()
{
    int i, x, n = 10;
    STACK S;
    QUEUE Q;


    S.Top = NULL;
    Q.Head = NULL;
    Q.Tail = NULL;

    printf("Enter count of elements\n");
    scanf("%d", &n);

    printf("Queue:\n");
    for (i = 0; i < n; i++)
    {
        if (Put(&Q, i) == FALSE)
            break;
    }
    n = i;
    for (i = 0; i < n; i++)
    {
        Get(&Q, &x);
        printf("%7d ", x);
    }
    printf("\n\n");
}
