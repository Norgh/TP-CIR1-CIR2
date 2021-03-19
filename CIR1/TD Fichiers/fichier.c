#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>







int main() {
	setlocale(LC_ALL, "fr-FR");
	
	FILE* Fichier;
	errno_t err = fopen_s(&Fichier, "fichier.txt", "w+");

	char Buffer[10];
	char Read[1000];
	char Ligne[] = "\n";

	if (Fichier!=NULL)
	{
		for (int i = 1;i <= 1000;i++)
		{
			_itoa_s(i, Buffer, 10, 10);
			sprintf_s(Buffer, 10, Buffer);
			fputs(Buffer, Fichier);
			fputs(Ligne, Fichier);
		}
	}

	fseek(Fichier, 0, SEEK_SET);
	while (!feof(Fichier))
	{
		fgets(Read, 1000, Fichier);
		printf("%s", Read);
	}
	fclose(Fichier);
}