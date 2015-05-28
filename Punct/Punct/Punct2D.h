#pragma once

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
};