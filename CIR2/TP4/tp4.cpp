#include <iostream>
#include <locale>

using namespace std;
#define pi 3.14159265359

class A {
public:
	A() { x = 0; cout << "1"; }
	A(int px) { x = px; cout << "2"; }
	A(const A& pa) { x = pa.x; cout << "3"; }
protected:
	int x;
};

class B {
public:
	B(const A& pa = A()) : a(pa) { y = 0; cout << "4"; }
	B(const A& pa, int py) { a = pa; y = py; cout << "5"; }
protected:
	A a;
	int y;
};

class Point {
private:
	float x, y; // private attributes
public:
	// constuctors
	Point(); // fill X Y with random values (from 0 to 100)
	Point(const float& newx, const float& newy);
	// fill XY values
	// Setters and getters
	void setXY(const float& newx, const float& newy);
	void setX(const float& newx);
	void setY(const float& newy);
	float getX();
	float getY();
	// other methods
	void print(); // prints the coordinates of the point
	float distanceTo(const Point& otherPoint);
};

Point::Point()
{
	x = (float)(rand() % 99);
	y = (float)(rand() % 99);
}

Point::Point(const float& newx, const float& newy)
{
	x = newx;
	y = newy;
}

void Point::setXY(const float& newx, const float& newy)
{
	x = newx;
	y = newy;
}

void Point::setX(const float& newx)
{
	x = newx;
}

void Point::setY(const float& newy)
{
	y = newy;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

void Point::print()
{
	cout << "X : " << x << "  Y : " << y << endl;
}

float Point::distanceTo(const Point& otherPoint)
{
	float rx = (otherPoint.x - x) * (otherPoint.x - x);
	float ry = (otherPoint.y - y) * (otherPoint.y - y);
	return sqrt(rx + ry);
}

class Circle
{
private:
	Point center;
	float radius;
public:
		Circle(float, float, float);
		float getRadius();
		void setRadius(float r);
		float getCenterX();
		float getCenterY();
		float getArea();
		float getPerimeter();
};

Circle::Circle(float x, float y, float r) :
	center(x, y), radius(r)
{
	center.setXY(x, y);
	setRadius(r);
}

float Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getCenterX()
{
	return center.getX();
}

float Circle::getCenterY()
{
	return center.getY();
}

float Circle::getArea()
{
	return ((float)pi * radius * radius);
}

float Circle::getPerimeter()
{
	return (2 * (float)pi * radius);
}

class Vector
{
private:
	float x, y;
public:
	Vector(Point A, Point B);
	Vector getSum(Vector& otherVector);
	Vector getResult(int r);
	bool verifyEquality(Vector& otherVector);
	void print();
};

void Vector::print()
{
	cout << "X : " << x << "  Y : " << y << endl;
}

Vector::Vector(Point A, Point B)
{
	x = B.getX() - A.getX();
	y = B.getY() - A.getY();
}

Vector Vector::getSum(Vector& otherVector)
{
	Point P, Q;
	Vector sum(P, Q);
	sum.x = (otherVector.x + x);
	sum.y = (otherVector.y + y);
	sum.print();
	return sum;
}

Vector Vector::getResult(int r)
{
	Point P, Q;
	Vector sum(P, Q);
	sum.x = (x * r);
	sum.y = (y * r);
	sum.print();
	return sum;
}

bool Vector::verifyEquality(Vector& otherVector)
{
	if (otherVector.x == x && otherVector.y == y) return true;
	else return false;
}

class Polygon
{
private :
	Point* points;
	int nbpts = 0;
public :
	Polygon(int size);
	float getArea();
	void print();
	void setPXY(int pt, float x, float y);
};

Polygon::Polygon(int size)
{
	points = new Point[size];
	nbpts = size;
}

void Polygon::print()
{
	for (int i = 0; i < nbpts - 1; i++) 
	{
		cout << "Point n = " << i << "  X : " << points[i].getX() << "  Y : " << points[i].getY() << endl;
	}
}

void Polygon::setPXY(int pt,float x, float y)
{
	points[pt].setXY(x, y);
}

float Polygon::getArea()
{
	float area=0;
	for (int i = 0; i < nbpts - 2;i++)
	{
		area = area + (((points[i].getX()) * (points[i + 1].getY())) - ((points[i + 1].getX()) * (points[i].getY()))/2);
	}
	return area;
}

int main() {

	srand((int)time(NULL));
	setlocale(LC_ALL, "FR-fr");
	// EXERCICE 1
	/*cout << "-- A --\n";
	A a0; cout << endl;
	A a1(3); cout << endl;
	A a2(a1); cout << endl;
	A a3 = a2; cout << endl;
	a3 = a1; cout << endl;
	cout << "-- B --\n";
	B b0(a0, 3); cout << endl;
	B b1(a1); cout << endl;
	B b2; cout << endl; */
	/*-- A --
	1 variable sans valeur passée en paramètre
	2 variable avec int passé en paramètre
	3 variable avec adresse passée en paramètre
	3 variable égale à une autre variable de la même classe

	-- B --
	15 variable avec variable d'une autre classe précédente passée en paramètre ainsi qu'un int
	34 variable avec adresse d'une autre classe précédente passée en paramètre
	134 variable sans paramètres, le résultat est un A crée sans valeur précise donnée masi également l'adresse de celle-ci
	
	// EXERCICE 2
	
	float x, y, r;
	cout << "Entrez une valeur de x : ";
	cin >> x;
	cout << endl << "Entrez une valeur de y : ";
	cin >> y;
	cout << endl << "Entrez une valeur de r : ";
	cin >> r;
	Circle test(x, y, r);
	system("PAUSE");
	system("CLS");
	
	// EXERCICE 3

	Point A, B, C, D;
	Vector Test1(A, B), Test2(C, D);
	Test1.getResult(10);
	Test1.getSum(Test2);
	cout << Test1.verifyEquality(Test2);
	*/
	// EXERCICE 4

	Polygon Triangle(3);
	Triangle.setPXY(0, 1, 0);
	Triangle.setPXY(1, 1, 3);
	Triangle.setPXY(2, 3, 2);
	cout << "Triangle : " << Triangle.getArea() << endl;
	Polygon Carré(4);
	Carré.setPXY(0, 0, 0);
	Carré.setPXY(1, 10, 10);
	Carré.setPXY(2, 0, 10);
	Carré.setPXY(3, 10, 0);
	cout << "Carré : " << Carré.getArea() << endl;
	Polygon Rectangle(4);
	Rectangle.setPXY(0, 0, 0);
	Rectangle.setPXY(1, 10, 20);
	Rectangle.setPXY(2, 0, 20);
	Rectangle.setPXY(3, 10, 0);
	cout <<"Rectangle : " << Rectangle.getArea() << endl;
	Polygon Pentagone(5);
	Pentagone.setPXY(0, 10, 0);
	Pentagone.setPXY(1, 30, 10);
	Pentagone.setPXY(2, 0, 20);
	Pentagone.setPXY(3, 30, 25);
	Pentagone.setPXY(4, 10, 30);
	cout << "Pentagone : " << Pentagone.getArea() << endl;



}