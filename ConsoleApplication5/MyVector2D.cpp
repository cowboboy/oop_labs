#include "MyVector2D.h"
#include <cstdio>

MyVector2D::MyVector2D()
{
	X = 0;
	Y = 0;
	printf("MyVector2D() for \"%d\" with x=\"%d\" y=\"%d\"\n", (int)this % 1000, X, Y);
}

MyVector2D::MyVector2D(int x, int y)
{
	X = x;
	Y = y;
}

MyVector2D::MyVector2D(const MyVector2D& vector)
{
	X = vector.X;
	Y = vector.Y;
	printf("MyVector2D(const MyVector2D& vector) for \"%d\" with x=\"%d\" y=\"%d\"\n", (int)this % 1000, X, Y);
}

int MyVector2D::getX()
{
	return X;
}

int MyVector2D::getY()
{
	return Y;
}

MyVector2D::~MyVector2D()
{
	printf("~MyVector2D() for \"%d\" with x=\"%d\" y=\"%d\"\n", (int)this % 1000, X, Y);
}
