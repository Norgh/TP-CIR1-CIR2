#include <iostream>
#include <locale>
using namespace std;

class Fraction {
private:
	int num = 0;
	int den = 1;
public:
	Fraction();
	Fraction(int num, int den);
	void print();
	Fraction operator+(const Fraction&);
	Fraction operator+(const int&);
	friend Fraction operator+(int i, const Fraction& f);
	Fraction operator-(const Fraction& other);
	Fraction operator*(const Fraction& other);
	Fraction operator/(const Fraction& other);
	Fraction operator+= (const Fraction& other);
	operator int();
	void setNum(int num) {
		this->num = num;
	}
	void setDen(int den) {
		this->den = den;
	}
};

void Fraction::print() {
	cout << num << "/" << den << endl;
}

Fraction::Fraction() {
	cout << "Fraction() builds 0/1" << endl;
	 this->num = 0;
	 this->den = 1;
}
Fraction::operator int()
{
	cout << "Fraction -> int" << endl;
	return num / den; // renvoie la division entière
}

Fraction::Fraction(int num, int den) {
	cout << "Fraction(int, int) builds " << num << "/" << den << endl;
	setNum(num);
	setDen(den);
}

Fraction Fraction::operator+(const int& i)
{
	cout << "Fraction + int" << endl;
	return Fraction(this->num * i + this->den *i, this->den * i);
};

Fraction Fraction::operator+(const Fraction& other)
{
	cout << "Fraction + Fraction" << endl;
	return Fraction(this->num * other.den + this->den * other.num, this->den * other.den);
};

Fraction operator+(int i, const Fraction& f)
{
	cout << "int + Fraction" << endl;
	return Fraction(f.num * i + f.den * i, f.den * i);
}

Fraction Fraction::operator-(const Fraction& other) {
	return Fraction(this->num * other.den - this->den * other.num, this->den * other.den);
}

Fraction Fraction::operator*(const Fraction& other) {
	return Fraction(this->num * other.num, this->den * other.den);
}

Fraction Fraction::operator/(const Fraction& other) {
	return Fraction(this->num * other.den, this->den * other.num);
}

Fraction Fraction::operator+=(const Fraction& other) {
	return Fraction(this->num += other.num, this->den += other.den);
}

int main()
{
	setlocale(LC_ALL, "FR-fr");
	Fraction f1(1, 2);
	Fraction f2(1, 3);
	Fraction f3 = f1 + f2;
	Fraction f4=f3-f2;
	cout << "f1: "; f1.print();
	cout << "f2: "; f2.print();
	cout << "f3: "; f3.print();
	cout << "f4: "; f4.print();
}