#include <stdlib.h>
#include <stdio.h>

char lettres;
int x, y, z, n, tmp1, tmp2, tmp3, lettre, count = 1, i = 0;


void calcul()
{
	if (n % 2 == 0) { lettre = 4 * count + 2 * z + x * x + x + 2 * y + lettre + x * y * z * i; } //calcul pair
	else { lettre = 4 * count + z + z * z + 2 * x + 2 * y + lettre + x * y * z * i; } //calcul impair
	while (lettre > 26)
	{
		lettre -= 26;
	}
	if (lettre == 1) { lettres = 'A'; }
	if (lettre == 2) { lettres = 'B'; }
	if (lettre == 3) { lettres = 'C'; }
	if (lettre == 4) { lettres = 'D'; }
	if (lettre == 5) { lettres = 'E'; }
	if (lettre == 6) { lettres = 'F'; }
	if (lettre == 7) { lettres = 'G'; }
	if (lettre == 8) { lettres = 'H'; }
	if (lettre == 9) { lettres = 'I'; }
	if (lettre == 10) { lettres = 'J'; }
	if (lettre == 11) { lettres = 'K'; }
	if (lettre == 12) { lettres = 'L'; }
	if (lettre == 13) { lettres = 'M'; }
	if (lettre == 14) { lettres = 'N'; }
	if (lettre == 15) { lettres = 'O'; }
	if (lettre == 16) { lettres = 'P'; }
	if (lettre == 17) { lettres = 'Q'; }
	if (lettre == 18) { lettres = 'R'; }
	if (lettre == 19) { lettres = 'S'; }
	if (lettre == 20) { lettres = 'T'; }
	if (lettre == 21) { lettres = 'U'; }
	if (lettre == 22) { lettres = 'V'; }
	if (lettre == 23) { lettres = 'W'; }
	if (lettre == 24) { lettres = 'X'; }
	if (lettre == 25) { lettres = 'Y'; }
	if (lettre == 26) { lettres = 'X'; }
}

void variables()
{
	printf("Entrez la variable 1 : ");
	scanf_s("%d", &x);
	printf("Entrez la variable 2 : ");
	scanf_s("%d", &y);
	printf("Entrez la variable 3 : ");
	scanf_s("%d", &z);
	tmp1 = x;
	tmp2 = y;
	tmp3 = z;
}

void nouveaumot()
{
	int choix;
	printf("\n1) Encoder un autre mot\n2) Arreter\n");
	scanf_s("%d", &choix);
	if (choix == 1)
	{
		tmp1++;
		tmp2++;
		tmp3++;
		x = tmp1;
		y = tmp2;
		z = tmp3;
		count++;
		i = 0;
		system("cls");
		main();
	}
	else
	{
		return 0;
	}
}

void clavier()
{
	printf("\nEntrez votre lettre : ");
	lettres = readChar("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	printf("%c", lettres);
	if (lettres == 'A' || lettres == 'a') { lettre = 1; }
	if (lettres == 'B' || lettres == 'b') { lettre = 2; }
	if (lettres == 'C' || lettres == 'c') { lettre = 3; }
	if (lettres == 'D' || lettres == 'd') { lettre = 4; }
	if (lettres == 'E' || lettres == 'e') { lettre = 5; }
	if (lettres == 'F' || lettres == 'f') { lettre = 6; }
	if (lettres == 'G' || lettres == 'g') { lettre = 7; }
	if (lettres == 'H' || lettres == 'h') { lettre = 8; }
	if (lettres == 'I' || lettres == 'i') { lettre = 9; }
	if (lettres == 'J' || lettres == 'j') { lettre = 10; }
	if (lettres == 'K' || lettres == 'k') { lettre = 11; }
	if (lettres == 'L' || lettres == 'l') { lettre = 12; }
	if (lettres == 'M' || lettres == 'm') { lettre = 13; }
	if (lettres == 'N' || lettres == 'n') { lettre = 14; }
	if (lettres == 'O' || lettres == 'o') { lettre = 15; }
	if (lettres == 'P' || lettres == 'p') { lettre = 16; }
	if (lettres == 'Q' || lettres == 'q') { lettre = 17; }
	if (lettres == 'R' || lettres == 'r') { lettre = 18; }
	if (lettres == 'S' || lettres == 's') { lettre = 19; }
	if (lettres == 'T' || lettres == 't') { lettre = 20; }
	if (lettres == 'U' || lettres == 'u') { lettre = 21; }
	if (lettres == 'V' || lettres == 'v') { lettre = 22; }
	if (lettres == 'W' || lettres == 'w') { lettre = 23; }
	if (lettres == 'X' || lettres == 'x') { lettre = 24; }
	if (lettres == 'Y' || lettres == 'y') { lettre = 25; }
	if (lettres == 'Z' || lettres == 'z') { lettre = 26; }
}

int main()
{
	if (count == 1) { variables(); }
	printf("Entrez le nombre de lettres du mot : ");
	scanf_s("%d", &n);
	int tab[30];
	while (i != n)
	{
		clavier();
		calcul();
		tab[i] = lettres;
		i++;
	}
	printf("\nVotre mot transmissible est ");
	char tmp;
	for (int compteur = 0; compteur < n; compteur++)
	{
		tmp = tab[compteur];
		printf("%c", tmp);
		if (tmp == '\0') { break; }
	}
	nouveaumot();
}