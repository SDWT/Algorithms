#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>


int count = 0;

void findWords(char *A, char *word, int N);

void more()
{
	char word[] = "..."; // ����� �����. ��� ������ �����, ��� ������� �����
	
	findWords("more", word, 0);
}

void findWords(char *A, char *word, int N)
{
	int i;
	char * w;
	if (N == strlen(word)) // ����� ���������
	{
		printf("%d %s\n", ++count, word);
		return;
	}
	
	w = word;	
	for (i = 0; i < strlen(A); i++)
	{
		w[N] = A[i];
		findWords(A, w, N + 1); // ��������
	}
}


int main(int argc, char argv[]){
	//setlocale(LC_ALL, "Russian");
	more();


	//system("pause");
	return 0;
}