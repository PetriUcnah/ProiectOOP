#pragma once
#include "Punct2D.h"
#include <string>

using namespace std;

class Punct2DColorat : public Punct2D{
public:
	Punct2DColorat(string,int,int);
private:
	string culoare;

protected:
	void setCuloare(string);

public:
	string getCuloare();
	//friend ostream& operator<<(ostream& out, const Punct2DColorat&);

};