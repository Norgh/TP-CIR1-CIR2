#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include<string>
#include<sstream>
#define multiplier(x,y) ((x) * (y))

using namespace std;
using std::cout;
using std::cin;

class TextRectangle
{
private:
	int width;
	int height;
public:
	int getWidth();
	int getHeight();
	void setWidth(int width);
	void setHeight(int height);
	int getArea();
	int getPerimeter();
	void print();
	void drawArea(const char& pattern);
	void drawPerimeter(const char& pattern);
};

int TextRectangle::getWidth() 
{
	return width;
}

int TextRectangle::getHeight()
{
	return height;
}

void TextRectangle::setWidth(int w)
{
	if (w > 10)
	{
		cout << "Width must be <= 10" << endl;
		cout << "Width : " << endl;
		cin >> w;
	}
	if (w <= 10)
	{
		width = w;
	}
}

void TextRectangle::setHeight(int h)
{
	if (h > 10)
	{
		cout << "Height must be <= 10" << endl;
		cout << "Height : " << endl;
		cin >> h;
	}
	if (h <= 10)
	{
		height = h;
	}
}

int TextRectangle::getArea()
{
	int area = width * height;
	return area;
}

int TextRectangle::getPerimeter()
{
	int perimeter = 2 * width + 2 * height;
	return perimeter;
}

void TextRectangle::print() 
{
	cout << "Width : " << width << endl;
	cout << "Height : " << height << endl;
	cout << "Area : " << getArea() << endl;
	cout << "Perimeter : " << getPerimeter() << endl;
}

void TextRectangle::drawArea(const char& pattern) 
{
	for (int i = 0;i < width; i++) 
	{
		for (int j = 0;j < height; j++)
		{
			cout << pattern;
		}
		cout << endl;
	}
}

void TextRectangle::drawPerimeter(const char& pattern)
{
	for (int i = 0;i < height; i++)
	{
		for (int j = 0;j < width; j++)
		{
			if(j==0 || j==width-1)
			{
				cout << pattern;
			}
			else
			{
				if (i == 0 || i == height - 1)
				{
					cout << pattern;
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "fr-FR");
	
	// EXERCICE 1

	int a;
	int b;
	cout << "Entrez une valeur :" << endl;
	cin >> a;
	cout << "Entrez une autre valeur :" << endl;
	cin >> b;
	cout << multiplier(a+1, b+1) << endl;
	system("PAUSE");
	system("CLS");

	// EXERCICE 2

	int c;
	cout << "Entrez la valeur du chiffre dont vous souhaitez afficher la table de multiplication" << endl;
	cin >> c;
	system("CLS");
	for (int i = 1; i <= 10; i++)
	{
		cout << multiplier(c,i) << " | ";
	}
	cout << endl;
	system("PAUSE");
	system("CLS");
	for (int i = 1; i <= 10; i++)
	{
		cout << setw(50) << multiplier(c, i) << endl;
	}
	system("PAUSE");
	system("CLS");
	
	// EXERCICE 3

	ifstream file;
	file.open("text.txt");
	string line;
	string word;
	int nbword=0;
	int nbline=0;
	int nbcharacters=0;
	int tab[255] ={};
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			nbline++;
			stringstream ss(line);
			while (ss >> word)
			{
	//			for (unsigned c=0;c<word.size(); c++)
	//			{
	//				word[c] = tolower(word[c]);
	//				if (isalpha(word[c])) ++tab[word[c]];
	//			}
				 for (auto &c : word)
				{
					c = tolower(c);
					if (isalpha(c)) ++tab[c];
				}
				nbword++;
				nbcharacters=nbcharacters+word.size();
			}
		}
	}
	file.close();
	cout << "Le nombre de caracteres est de : "<< nbcharacters << endl;
	cout << "Le nombre de mots est de : " << nbword << endl;
	cout << "Le nombre de lignes est de : " << nbline << endl;
	system("PAUSE");
	system("CLS");
	for (auto i = 0; i < 255;i++)
	{
		if(tab[i]) cout << char(i) << " : " << tab[i] << endl;
	}
	system("PAUSE");
	system("CLS");
	
	// EXERCICE 4
	
	char rect;
	int w, h;
	TextRectangle rectangle;
	cout << "Enter a width : " << endl;
	cin >> w;
	cout << "Enter a height : " << endl;
	cin >> h;
	rectangle.setWidth(w);
	rectangle.setHeight(h);
	rectangle.print();
	cout << "Entrez un caractère : ";
	cin >> rect;
	cout << endl;
	rectangle.drawArea(rect);
	cout << endl;
	rectangle.drawPerimeter(rect);
}