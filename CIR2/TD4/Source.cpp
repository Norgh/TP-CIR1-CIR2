#include <iostream>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <array>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <chrono>

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 4;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;


using namespace std;

//= ================================================            Partie 1            ================================================ = //

// Question :    Avec 6 villes, il existe 120 tournées pour un scénario.



//= ================================================            Partie 2            ================================================ = //

void toutesLesPermutations(string & villes, int debut, int fin);

/// \brief Methode recursive generant l ensemble des mots possibles
/// avec les caractères du mots villes donne en parametre.
void toutesLesPermutations(string& villes, int debut, int fin)
{
    if (debut == fin)
        cout << villes << endl;
    else
    {
        // Permutations made
        for (int i = debut; i <= fin; i++)
        {
            // echange des deux lettres
            swap(villes[debut], villes[i]);
            // Appel Recursif
            toutesLesPermutations(villes, debut + 1, fin);
            // On revient à la situation précédente
            swap(villes[debut], villes[i]);
        }
    }
}


void toutesLesPermutations(vector <string> vecteurDeNomsDeVille, int debut)
{
    if (debut == vecteurDeNomsDeVille.size() - 1)
    {
        for (int i = 0;i < (int)vecteurDeNomsDeVille.size();i++) cout << vecteurDeNomsDeVille[i]<<" ";
        cout << endl;
    }
    else
    {
        // Permutations made
        for (int i = debut; i < (int)vecteurDeNomsDeVille.size(); i++)
        {
            // echange des deux lettres
            swap(vecteurDeNomsDeVille[debut], vecteurDeNomsDeVille[i]);
            // Appel Recursif
            toutesLesPermutations(vecteurDeNomsDeVille, debut + 1);
            // On revient à la situation précédente
            swap(vecteurDeNomsDeVille[debut], vecteurDeNomsDeVille[i]);
        }
    }
}

vector<string> generationVilles()
{
    vector<string> myVector;
    for (auto i = 0; i < nombreDeVilles; i++)
    {
        string monStringTemp;
        int ASCIItempLettre;
        int nbLettresNomVille = tailleMinNomVille + rand() % (tailleMaxNomVille - tailleMinNomVille + 1);
        ASCIItempLettre = codeASCIIde_A + rand() % (nombreDeLettres);
        monStringTemp.push_back(char(ASCIItempLettre));
        for (auto j = 1; j < nbLettresNomVille; j++)
        {
            ASCIItempLettre = codeASCIIde_a + rand() % (nombreDeLettres);
            monStringTemp.push_back(char(ASCIItempLettre));
        }
        myVector.push_back(monStringTemp);
    }
    return myVector;
}

int main()
{
    srand(grainePourLeRand);
    vector<string> Test = generationVilles();
    toutesLesPermutations(Test, 0);
    return 0;
}
