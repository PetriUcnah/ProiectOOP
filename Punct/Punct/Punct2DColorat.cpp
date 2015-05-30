#include "Punct2DColorat.h"
#include "Punct2D.h"
#include <iostream>
#include <string.h>

using namespace std;

Punct2DColorat::Punct2DColorat(char* culoare, int x, int y) : Punct2D(x, y){
	setCuloare(culoare);
	setX(x);
	setY(y);
}

void Punct2DColorat::setCuloare(char* culoare){
	this->culoare = culoare;
}

char* Punct2DColorat::getCuloare(){
	return culoare;
}

ostream& operator<<(ostream& out, Punct2DColorat* punct)
{
	out << endl << "X: " << punct->getX() << endl;
	out << "Y: " << punct->getY() << endl;
	out << "Culoare: " << punct->getCuloare() << endl;
	return out;
}