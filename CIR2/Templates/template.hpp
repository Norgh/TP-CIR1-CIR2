#pragma once
using namespace std;
namespace mon_template 
{
	template <typename T>
	T max(const T& a, const T& b)
	{
		return(a > b ? a : b);
	}

	template <typename S>
	S swap(S a, S b)
	{
		S temp;
		temp = a;
		a = b;
		b = temp;
		return a, b;
	}
}

