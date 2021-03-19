#include <iostream>
#include <algorithm>
#include <locale>
#include <vector>
#include<ctime>
#include "header.hpp"

using namespace std;

float randomFloat(float const& min, float const& max)
{
	float myRandom;
	do
	{
		myRandom = min + ((float)rand() / ((float)RAND_MAX) * ((float)max + 1 - (float)min));
	} while (myRandom > max);
	return myRandom;
}

int main() {

	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "fr-FR");
	vector<int> myVector;
	int n = 0;
	cout << " Entrez le nombre de valeurs : ";
	cin >> n;
	int nombreRecherche = 0;
	cout << " Entrez le nombre recherché : ";
	cin >> nombreRecherche;
	for (int i = 0; i < n; i++)
	{
		myVector.push_back((int)randomFloat(0, 1000));
	}

	sort(myVector.begin(), myVector.end());
	int v = 0;
	for (auto i : myVector)
	{
		cout << i << ' ';
		v++;
		//if ((v % 5) == 0)
		//{
		//	cout << endl;
		//}
	}
		
	/*int mid, min = 0, max = myVector.size() - 1;
	while (min < max)
	{
		mid = (min + max) / 2;
		if (myVector[mid] < nombreRecherche)
		{
			min = mid + 1;
		}
		else 
		{
			max = mid;
		}
	}
	if (myVector[min] == nombreRecherche)
	{
		cout << "\nNumbeer has been found (drunk)";
	}
	else
	{
		cout << "\nNumbeer has not been found (drunk)";
	}*/
	//int distance;
	//vector<int>::iterator iterateurMid;
	//auto iterateurMin = myVector.begin();
	//auto iterateurMax = --myVector.end();

	//while (iterateurMin < iterateurMax)
	//{
	//	distance = std::distance(iterateurMin, iterateurMax) / 2;
	//	distance += std::distance(myVector.begin(), iterateurMin);
	//	iterateurMid = myVector.begin() + distance;

	//	if(*iterateurMid < nombreRecherche)
	//	{
	//		iterateurMin = iterateurMid;
	//		advance(iterateurMin, 1);
	//	}
	//	else 
	//	{
	//		iterateurMax = iterateurMid;
	//	}
	//}
	//if (*iterateurMin == nombreRecherche)
	//{
	//	cout << "\nNumbeer has been found (drunk)";
	//}
	//else
	//{
	//	cout << "\nNumbeer has not been found (drunk)";
	//}

	if (binary_search(myVector.begin(), myVector.end(), nombreRecherche))
	{
		cout << "\nNumbeer has been found (drunk)";
	}
	else 
	{
		cout << "\nNumbeer has not been found (drunk)";
	}


}
