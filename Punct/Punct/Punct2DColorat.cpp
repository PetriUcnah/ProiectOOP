#include "Punct2DColorat.h"
#include "Punct2D.h"
#include <iostream>
#include <string>

using namespace std;

Punct2DColorat::Punct2DColorat(string culoare, int x, int y) : Punct2D(x, y){
	setCuloare(culoare);
	setX(x);
	setY(y);
}

string Punct2DColorat::getCuloare(){
	return this->culoare;
}

void Punct2DColorat::setCuloare(string culoare){
	this->culoare = culoare;
}

ostream& operator<<(ostream& out, Punct2DColorat & punct)
{
	out << endl << "X: " << punct.getX() << endl;
	out << "Y: " << punct.getY() << endl;
	out << "Culoare: " << punct.getCuloare() << endl;
	return out;
}