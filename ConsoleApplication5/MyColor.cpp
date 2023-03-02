#include "MyColor.h"
#include <cstdio>

MyColor::MyColor()
{
	R = 0;
	G = 0;
	B = 0;
	printf("MyColor() for \"%d\" with r=\"%d\" g=\"%d\" b=\"%d\"\n", (int)this % 1000, R, G, B);
}

MyColor::MyColor(int r, int g, int b)
{
	R = r;
	G = g;
	B = b;
}

MyColor::MyColor(const MyColor& c)
{
	R = c.R;
	G = c.G;
	B = c.B;
	printf("MyColor(const MyColor& c) for \"%d\" with r=\"%d\" g=\"%d\" b=\"%d\"\n", (int)this % 1000, R, G, B);
}

void MyColor::editColor(int r, int g, int b)
{
	R = r;
	G = g;
	B = b;
}

std::string MyColor::viewColor()
{
	std::string result = "r=" + std::to_string(R) + "g=" + std::to_string(G) + "b=" + std::to_string(B) + "\n";
	return result;
}

MyColor::~MyColor()
{
	printf("~MyColor() for \"%d\" with r=\"%d\" g=\"%d\" b=\"%d\"\n", (int)this % 1000, R, G, B);
}
