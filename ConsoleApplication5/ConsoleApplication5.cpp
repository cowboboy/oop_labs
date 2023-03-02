#include <iostream>
#include "MyVector2D.h"
#include "MyColor.h"
#include <cstdio>

class Rectangle {
protected:
	MyVector2D leftTop;
	MyVector2D rightBottom;
public:
	Rectangle() : leftTop(), rightBottom() {
		printf("Rectangle() for \"%d\"\n", (int)this % 1000);
	}
	Rectangle(const MyVector2D& vector1, const MyVector2D& vector2) : leftTop(vector1), rightBottom(vector2) {
	}
	Rectangle(const Rectangle& rec) {
		leftTop = rec.leftTop;
		rightBottom = rec.rightBottom;
	}
	void ouputCoords() {
		printf("Coords of rectangle x1=%d, y1=%d, x2=%d, y2=%d\n", leftTop.getX(), leftTop.getY(),
			rightBottom.getX(), rightBottom.getY());
	}
	~Rectangle() {
		printf("~Rectangle() for \"%d\"\n", (int)this % 1000);
	}
};

class ColoredRectangle : public Rectangle{
	MyColor* color;
public:
	ColoredRectangle() : Rectangle() {
		color = new MyColor();
		printf("ColoredRectangle() for \"%d\"\n", (int)this % 1000);
	}
	ColoredRectangle(const MyVector2D& vector1, const MyVector2D& vector2, const MyColor& color) : Rectangle(vector1, vector2) {
		this->color = new MyColor(color);
	}
	ColoredRectangle(const ColoredRectangle& colRec) {
		color = new MyColor(*colRec.color);
	}
	void changeColorByPos() {
		int ratio = leftTop.getX() + rightBottom.getY();
		color->editColor(ratio % 255, ratio % 255, ratio % 255);
	}
	void viewColor() {
		printf("Color of ColoredRectangle is: %s", color->viewColor().c_str());
	}
	~ColoredRectangle() {
		delete color;
		printf("~ColoredRectangle() for \"%d\"\n", (int)this % 1000);
	}
};

class TestParent {
	int somefield;
public:
	TestParent() {
		printf("TestParent() for \"%d\"\n", (int)this % 1000);
	}
	~TestParent() {
		printf("~TestParent() for \"%d\"\n", (int)this % 1000);
	}
};

class TestChild : public TestParent {
public:
	int something;
};

int main()
{
	ColoredRectangle colRec1;                                                               
	ColoredRectangle colRec2(MyVector2D(1, 2), MyVector2D(3, 7), MyColor(255, 255, 255));     
	colRec2.viewColor();
	colRec2.changeColorByPos();
	colRec2.viewColor();
	ColoredRectangle colRec3(colRec1);
	ColoredRectangle* colRec4 = new ColoredRectangle();                                       
	delete colRec4;

	Rectangle* myRec1 = new Rectangle();
	Rectangle* myRec2 = new ColoredRectangle();

	TestChild myChild;
	myChild.something = 5;
	printf("\n%d\n", myChild.something);
}
