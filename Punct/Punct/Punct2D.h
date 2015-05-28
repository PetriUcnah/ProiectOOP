#pragma once
#include <iostream>

using namespace std;

class Punct2D{
public:
	Punct2D(int ,int);
private:
	int x;
	int y;

protected:
	void setX(int);
	void setY(int);

public:
	int getX();
	int getY();
	friend ostream& operator<<(ostream& out, Punct2D&);
};