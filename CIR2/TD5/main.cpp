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

using namespace std;
const int TAILLEDUGRAPHE = 6;
const int INFINI = 9999999;

class Graphe
{
private:
    std::vector<T> vecSommets;
    int arcs[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
    int cheminCourt[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
    int pointChemin[TAILLEDUGRAPHE][TAILLEDUGRAPHE];

public:
    void init();
};

void Graphe::init()
{
    for (int i = 0; i < TAILLEDUGRAPHE; i++)
    {
        for (int j = 0; j < TAILLEDUGRAPHE; j++)
        {
            arcs[i][j] = INFINI;
        }
    }
    arcs[0][1] = 40;
    arcs[0][2] = 230;
    arcs[1][2] = 200;
    arcs[2][3] = 250;
    arcs[2][4] = 425;
    arcs[3][4] = 190;
    arcs[4][5] = 300;

    for (int i = 0; i < TAILLEDUGRAPHE; i++)
    {
        for (int j = 0; j < TAILLEDUGRAPHE; j++)
        {
            if (arcs[i][j] == INFINI) pointChemin[i][j] = INFINI;
            else pointChemin[i][j] = -1;
        }
    }

}

int main()
{
    setlocale(LC_ALL, "fr-FR");

    Graphe test;
    std::vector<string> listeSommets;
    listeSommets.push_back("Lille");
    listeSommets.push_back("Lens");
    listeSommets.push_back("Paris");
    listeSommets.push_back("Bourge");
    listeSommets.push_back("Montpellier");
    test.init();
}