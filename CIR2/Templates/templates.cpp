#include <iostream>
#include <locale>
#include "template.hpp"
#include <vector>
#include <algorithm>

int main()
{
	int a = 1, b = 2;
	int c = mon_template::max(a, b);
	cout << c << endl;

	float d = 1, e = 2;
	float f = mon_template::max(a, b);
	cout << f << endl;
	float g = 12.3, h = 42.78;
	float i = mon_template::swap(g, h);
	cout << i << endl;

	int input;
	vector <int> ivec;
	// Lecture
	while (cin >> input) ivec.push_back(input);
	// Tri
	sort(ivec.begin(), ivec.end());
	// Sortie
	for (auto elem : ivec) cout << elem << " ";

	cout << endl;
	return 0;
}