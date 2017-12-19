
#include "stack.h"


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

int Pop( STACK *S, char *OldData )
{
  LIST *OldElement;

  if (S->Top == NULL)
      return FALSE;

  OldElement = S->Top;
  S->Top = S->Top->Next;

  if (OldData != NULL)
    *OldData = OldElement->Data;

  free(OldElement);

  return TRUE;
}


int Push( STACK *S, char NewData )
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
