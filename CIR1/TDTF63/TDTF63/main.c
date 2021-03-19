#include <stdlib.h>
#include <stdio.h>

int puissance_recurs(int a, int b) 
{
	if (b == 0) { return 1; }
	if (b == 1) { return a; }
	return (a * puissance_recurs(a, b - 1));
}

int fibo_naive(int n) 
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	return fibo_naive(n - 1) + fibo_naive(n - 2);
}

int PGCD_recurs(int a, int b) 
{
	int r = a % b;
	if (r == 0) { return b; }
	return PGCD_recurs(b, r);
}

int MyFct(int n, int accu) 
{
	if (n == 0) return accu;
	return MyFct(n - 1, accu + n);
}

int Factorielle(int n, int acc)
{
	if (n == 0) return acc;
	return Factorielle(n - 1, n * acc);
}

int palindrome(char tab[256]) 
{











}


int main() {
	
	 system("start chrome.exe https://www.youtube.com/watch?v=RHQC4fAhcbU ");
	//system("start dxdiag.exe");
	//system("start regedit.exe");



}