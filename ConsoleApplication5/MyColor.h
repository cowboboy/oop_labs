#pragma once
#include <string>
class MyColor
{
	int R, G, B;
public:
	MyColor();
	MyColor(int r, int g, int b);
	MyColor(const MyColor& c);
	void editColor(int r, int g, int b);
	std::string viewColor();
	~MyColor();
};

