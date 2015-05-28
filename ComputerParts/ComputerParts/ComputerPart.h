#pragma once
#include <string>
using namespace std;

class ComputerPart {

private:
	int price;
	string name;

protected:
	virtual void setPrice(int price);
	virtual void setName(string name);

public:
	virtual int getPrice();
	virtual string getName();
};