/* 2. Добавить в программу “реализация стека на основе односвязного списка”
 * проверку на выделение памяти. Если память не выделяется, то выводится
 * соответствующее сообщение. Постарайтесь создать ситуацию, когда память не
 * будет выделяться (добавлением большого количества данных).
 *
 * 5. *Реализовать очередь
 * а) На основе массива
 * б) *На основе односвязного списка
 *
 * ###6. ***Реализовать двухстороннюю очередь.
 *
 * Samsonov Dmitriy
 */


#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <locale.h>
#include "list.h"
#include "queuemas.h"

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
            "1 - show stack and queue;\n" \
            "2 - check stack and queue max count of elements;\n" \
            "\n");
        switch (_getch())
        {
        case '0':
            flag = 0;
            break;
        case '1':
            ShowWork();
            break;
        case '2':
            CheckMemory();
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
    QUEUEMAS QM;


    S.Top = NULL;
    Q.Head = NULL;
    Q.Tail = NULL;
    QM.Head = 0;
    QM.Tail = 0;

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
    printf("\nStack:\n");
    for (i = 0; i < n; i++)
    {
        if (Push(&S, i) == FALSE)
            break;
    }
    n = i;
    for (i = 0; i < n; i++)
    {
        Pop(&S, &x);
        printf("%7d ", x);
    }
    printf("\nQueue Massive:\n");
    for (i = 0; i < n; i++)
    {
        if (PutQMas(&QM, i) == FALSE)
            break;
    }
    n = i;
    for (i = 0; i < n; i++)
    {
        GetQMas(&QM, &x);
        printf("%7d ", x);
    }
    printf("\n\n");
}

void CheckMemory()
{
    int i, x, n = 1000000000;
    STACK S;
    QUEUE Q;
    QUEUEMAS QM;
    
    S.Top = NULL;
    Q.Head = NULL;
    Q.Tail = NULL;
    QM.Head = QM.Tail = 0;

    printf("Start Queue check:\n");
    for (i = 0; i < n; i++)
    {
        if (Put(&Q, i) == 0)
            break;
    }
    n = i;
    printf("Max of elements in Queue: %d\n", n);
    for (i = 0; i < n; i++)
    {
        Get(&Q, &x);
        /*printf("%7d ", x);*/
    }
    printf("End of check Queue.\n\n");

    n = 1000000000;
    printf("Start Stack check:\n");
    for (i = 0; i < n; i++)
    {
        if (Push(&S, i) == 0)
            break;
    }
    n = i;
    printf("Max of elements in Stack: %d\n", n);
    for (i = 0; i < n; i++)
    {
        Pop(&S, &x);
        /*printf("%7d ", x);*/
    }
    printf("End of check Stack.\n\n");

    n = 1000000000;
    printf("Start QueueMas check:\n");
    for (i = 0; i < n; i++)
    {
        if (PutQMas(&QM, i) == 0)
            break;
    }
    n = i;
    printf("Max of elements in QueueMas: %d\n", n);
    for (i = 0; i < n; i++)
    {
        GetQMas(&QM, &x);
        /*printf("%7d ", x);*/
    }
    printf("End of check Queue.\n\n");
}

