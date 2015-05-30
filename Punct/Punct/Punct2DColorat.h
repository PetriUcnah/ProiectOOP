#pragma once
#include "Punct2D.h"
#include <string>
#include <iostream>

using namespace std;

class Punct2DColorat : public Punct2D{
public:
	Punct2DColorat(char*, int, int);

private:
	char* culoare;
	void setCuloare(char*);

public:
	char* getCuloare();
	friend ostream& operator<<(ostream& out, Punct2DColorat*);
};