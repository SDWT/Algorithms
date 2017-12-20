
#include "list.h"


void DisplayList( LIST *L )
{
  if (L == NULL)
    printf("<Empty List>\n");
  else
    while (L != NULL)
    {
      printf("%d", L->Data);
      printf((L = L->Next) == NULL ? "\n" : ",");
    }
}

int Put( QUEUE *Q, int NewData )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
  {
      printf("Error: Memory is full.\n");
      return FALSE;
  }

  NewElement->Data = NewData;
  NewElement->Next = NULL;

  if (Q->Head == NULL)
    Q->Head = NewElement;
  else
    Q->Tail->Next = NewElement;

  Q->Tail = NewElement;

  return TRUE;
}

int Get( QUEUE *Q, int *OldData )
{
  LIST *OldElement;

  if (Q->Head == NULL)
  {
      printf("Error: Queue is empty.\n");
      return FALSE;
  }

  OldElement = Q->Head;
  Q->Head = Q->Head->Next;

  if (OldData != NULL)
    *OldData = OldElement->Data;

  free(OldElement);

  return TRUE;
}

int Pop( STACK *S, int *OldData )
{
  LIST *OldElement;

  if (S->Top == NULL)
  {
      printf("Error: Stack is empty.\n");
      return FALSE;
  }

  OldElement = S->Top;
  S->Top = S->Top->Next;

  if (OldData != NULL)
    *OldData = OldElement->Data;

  free(OldElement);

  return TRUE;
}


int Push( STACK *S, int NewData )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
  {
      printf("Error: Memory is full.\n");
      return FALSE;
  }
  
  NewElement->Data = NewData;
  NewElement->Next = S->Top;
  S->Top = NewElement;

  return TRUE;
}
