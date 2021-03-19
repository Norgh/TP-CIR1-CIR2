#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#define TailleMaxTab 200

void InsertionTas(int Tab[TailleMaxTab]) {

	for (int i = 0;i < TailleMaxTab;i++)
	{

	}

}

void ExtractionTas(int Tab[TailleMaxTab]) {
	
	for (int i = TailleMaxTab;i > 0;i--)
	{
		
	}

}

void TriTas(int Tab[TailleMaxTab]) {

	for (int i = 0;i < TailleMaxTab;i++)
	{
		InsertionTas(Tab);
	}
	for (int i = 0;i < TailleMaxTab;i++)
	{
		ExtractionTas(Tab);
	}
}

int os = 0;

int OSEF(int Grid[20])
{

	for (int i = 0; i < 20; i++)
	{
		os++;
	}
	return os;
}

int main() {
	setlocale(LC_ALL, "FR-fr");
	srand(time(NULL));
	/*int Tas[TailleMaxTab];
	for (int i = 0;i < TailleMaxTab;i++) 
	{
		if (i%20 == 0) { printf("\n");}
		Tas[i] = rand() % 20;
		if (i == TailleMaxTab-1) {
			printf(" %d", Tas[i]);
		}
		else 
		{
			printf(" %d |", Tas[i]);
		}
	}*/
	int Grid[20];
	OSEF(Grid);
	printf("%d", os);





}