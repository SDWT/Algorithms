#pragma once

#define MaxElemOfQueue 100

typedef struct tagQueueMas
{
    int Head, Tail;
    int data[MaxElemOfQueue];
} QUEUEMAS;

int PutQMas(QUEUEMAS *Q, int NewData);

int GetQMas(QUEUEMAS *Q, int *OldData);
