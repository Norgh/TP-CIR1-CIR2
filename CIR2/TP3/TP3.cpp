#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cmath>
using namespace std;
using std::cout;
using std::cin;

class Point3D {
private:
	float x, y, z; // private attributes
public:
	// constuctors
	Point3D(); // fill X Y Z with random values (from 0 to 100)
	Point3D(const float& newx, const float& newy, const float& newz);
	// fill XYZ values
	// Setters and getters
	void setXYZ(const float& newx, const float& newy, const float
		& newz);
	void setX(const float& newx);
	void setY(const float& newy);
	void setZ(const float& newz);
	float getX();
	float getY();
	float getZ();
	// other methods
	void print(); // prints the coordinates of the point
	float distanceTo(const Point3D& otherPoint3D);
};

Point3D::Point3D() 
{
	x = (float)(rand() % 99);
	y = (float)(rand() % 99);
	z = (float)(rand() % 99);
}

Point3D::Point3D(const float& newx, const float& newy, const float& newz)
{
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setXYZ(const float& newx, const float& newy, const float& newz)
{
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setX(const float& newx)
{
	x = newx;
}
void Point3D::setY(const float& newy)
{
	y = newy;
}
void Point3D::setZ(const float& newz)
{
	z = newz;
}
float Point3D::getX()
{
	return x;
}
float Point3D::getY()
{
	return y;
}
float Point3D::getZ()
{
	return z;
}

void Point3D::print()
{
	cout << "X : " << x  << "  Y : " << y  << "  Z : " << z << endl;
}

float Point3D::distanceTo(const Point3D& otherPoint3D)
{
	float rx = (otherPoint3D.x - x) * (otherPoint3D.x - x);
	float ry = (otherPoint3D.y - y) * (otherPoint3D.y - y);
	float rz = (otherPoint3D.z - z) * (otherPoint3D.z - z);
	return sqrt(rx + ry + rz);
}

class Trajectory {
private:
	Point3D *points;
	int nbpts=0;
public:
	void print(); // print the coordinates of all points
	Point3D& getPoint(const int& n); // returns the reference of point n
	Trajectory(int size);
	float getTotalDistance();
	float getFirstLastPointDistance();
	void destructor();
};

Trajectory::Trajectory(int size)
{
	points = new Point3D[size];
	nbpts = size;
	float x = (float)(rand() % 11);
	float y = (float)(rand() % 11);
	float z = (float)(rand() % 11);
	float t;
	for (int i = 0; i < nbpts; i++)
	{
		t = (float)(rand() % 11);
		points[i].setXYZ(x * t, y * t, z * t);
	}
	float tmpx, tmpy, tmpz;
	for (int j = 0; j < nbpts; j++)
	{
		for (int i = 0; i < nbpts - 1; i++)
		{

			if (points[i].getX() > points[i+1].getX() || points[i].getY() > points[i + 1].getY() || points[i].getZ() > points[i + 1].getZ()) 
			{
				 tmpx = points[i].getX();
				 tmpy = points[i].getY();
				 tmpz = points[i].getZ();
				 points[i].setXYZ(points[i + 1].getX(), points[i + 1].getY(), points[i + 1].getZ());
				 points[i + 1].setXYZ(tmpx, tmpy, tmpz);
			}
		}
	}
}

void Trajectory::print()
{
	for(int i=0; i<nbpts; i++)
	{ 
		points[i].print();
	}
}

Point3D& Trajectory::getPoint(const int& n)
{
	return points[n];
}

float Trajectory::getTotalDistance()
{
	float total=0;
	for (int i=0 ; i < nbpts -1 ; i++)
	{
		total = total + (getPoint(i).distanceTo(getPoint(i + 1)));
	}
	return total;
}

float Trajectory::getFirstLastPointDistance()
{
	float distFirstLast = 0;
	distFirstLast = getPoint(0).distanceTo(getPoint(nbpts-1));
	return distFirstLast;
}

void Trajectory::destructor() 
{
	delete [] points;
}

template <class T> 
T Min(T x, T y)
{
	return x < y ? x : y;
}

int main() {
	setlocale(LC_ALL, "fr-FR");
	srand((int)time(NULL));

	// EXERCICE 1
	/*
	Point3D test(4,5,8);
	test.print();
	Point3D test2(9, 9, 9);
	cout << test.distanceTo(test2);
	system("PAUSE");
	system("CLS");
	*/
	// EXERCIE 2

	/*int size = 0;
	cout << "Entrez le nombre de points : ";
	cin >> size;
	Trajectory testeur(size);
	testeur.print();
	cout << testeur.getTotalDistance() << endl << testeur.getFirstLastPointDistance();
	testeur.destructor();*/
	float a = 2.5;
	float b = 6;
	cout << Min(a, b);

}