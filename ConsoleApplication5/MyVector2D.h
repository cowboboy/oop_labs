#pragma once
class MyVector2D
{
	int X, Y;
public:
	MyVector2D();
	MyVector2D(int x, int y);
	MyVector2D(const MyVector2D& vector);
	int getX();
	int getY();
	~MyVector2D();
};

