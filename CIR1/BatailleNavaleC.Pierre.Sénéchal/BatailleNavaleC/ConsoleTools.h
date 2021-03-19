#pragma once

#include <windows.h> 
#include <time.h>
#include <conio.h>
#include <string.h>

HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
WORD wOldColorAttrs;
CHAR chBuffer[256];
DWORD cRead, cWritten, fdwMode, fdwOldMode;
DWORD Mode;
DWORD wOldMode;

// attend la frappe d'une touche parmi celles spécifiées en paramètre
// ex: car =  readChar("onON");
char readChar(const char* filtre);
// permet d'utiliser les fonctions GotoXY et PlotChar (un seul appel en début de programme)
int openConsole();
// CloseConsole() doit être appelée après la dernière utilisation de GotoXY et PlotChar
int closeConsole();
// renvoie la taille de la console
COORD getConsoleSize();
// déplace le curseur en X,Y position du prochain affichage
void moveCursor(unsigned short int X, unsigned short int Y);
// affiche un caractère à la position du curseur
int plotChar(char SomeChar);
// renvoie une valeur entière aléatoire rang_min<= x < rang_max
int rangedRand(int range_min, int range_max);
// affiche un inversé vidéo de la zone de la taille (lenght x height) en postion pos pdt le tps duration en ms
int blink(COORD pos, DWORD length, DWORD height, DWORD duration);