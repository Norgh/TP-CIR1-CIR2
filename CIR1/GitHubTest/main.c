#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "fr-FR");
	char fin = 'O';
	char var;
	char mot[10];
	while (fin != 'X')
	{
		for (int i = 0 ; i < 10 ; i++)
		{
			var = (char)getch();
			mot[i] = var;
			printf("%c", mot[i]);
		}
			
		printf("\nLe mot entré est : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%c", mot[i]);
		}
		printf("\n");
		printf("\nAppuyez sur 'X' pour arrêter, sinon appuyer sur une autre touche\n");
		fin = (char) getch();
	}






}