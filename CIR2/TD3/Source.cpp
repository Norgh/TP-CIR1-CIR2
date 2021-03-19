#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <array>

using namespace std;

/*=================================================			Exo 2			=================================================*/

constexpr int n = 1500;

/*
* Prime number array
*/

std::array <int, n> tableau;


bool verifNombrePremier(int n)
{
	bool estPremier = true;
	int i = 2;

	while (estPremier && i < n)
	{
		if (n % i == 0)
		{
			estPremier = false;
		}
		else i++;
	}
	return estPremier;
}

/*=================================================			Exo 3			=================================================*/





int main() {

	/*
	* We create and then save the prime numbers
	*/
	int nbNbPremiers = 0;
	cout << "Prime numbers series : ";
	for (int i = 1; i < n; i++)
	{
		if (verifNombrePremier(i))
		{
			tableau.at(nbNbPremiers++) = i;
			cout << i << " ";
		}
	}
	cout << endl << endl << endl;
}