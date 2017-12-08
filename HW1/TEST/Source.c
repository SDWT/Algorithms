#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int count = 0;

void findWords(char * A, char * word, int N);

void more()
{
    char word[] = "...";   // Длина слова. Чем больше точек, тем длиннее слово
    findWords ( "more" , word , 0 );
}

void findWords(char * A, char * word, int N)
{
    int i;
    char * w;
    if (N == strlen(word))  // Слово построено
    {
        printf("%d %s\n", ++count, word);   return;
    }
    w = word;

    for (i = 0; i < strlen(A); i++)
    {
        w[N] = A[i];
        findWords(A, w, N + 1); // Рекурсия
    }
}

int main(int argc, char * argv[])
{
    more();
    return 0;
}
