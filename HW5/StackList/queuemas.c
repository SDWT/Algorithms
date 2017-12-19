
#include <stdio.h>
#include "queuemas.h"

int PutQMas(QUEUEMAS *Q, int NewData)
{
    if ((Q->Tail + 1) % MaxElemOfQueue == Q->Head % MaxElemOfQueue)
    {
        printf("Error: Queue is full.\n");
        return 0;
    }

    Q->data[(Q->Tail++) % MaxElemOfQueue] = NewData;
    Q->Head = Q->Head % MaxElemOfQueue;
    Q->Tail = Q->Tail % MaxElemOfQueue; 
    return 1;
}

int GetQMas(QUEUEMAS *Q, int *OldData)
{
    if (Q->Tail % MaxElemOfQueue == Q->Head % MaxElemOfQueue)
    {
        printf("Error: Queue is empty.\n");
        return 0;
    }

    *OldData = Q->data[Q->Head++];
    return 1;
}
