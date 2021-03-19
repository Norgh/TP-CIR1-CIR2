#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "ConsoleTools.h"

int main() {
	setlocale(LC_ALL, "FR-fr");
	char c = ' ';
	char Nbr[50];
	int i = 0;
	do{
		c = readChar("0123456789");
		if (c >= 0 && c <= 9) 
		{
			Nbr[i] = c;
			i++;
		}


	} while (c != '\r');




}