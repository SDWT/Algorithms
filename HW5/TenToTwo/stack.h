#ifndef __QUST_H_
#define __QUST_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100
#define TRUE 1
#define FALSE 0


typedef struct tagLIST LIST;
struct tagLIST
{
  int Data; 
  LIST *Next; 
};

typedef struct tagStack
{
  LIST *Top;
} STACK;

void DisplayList( LIST *L );

int Pop( STACK *S, int *OldData );

int Push( STACK *S, int NewData );

#endif
