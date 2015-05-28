#pragma once
#include <string>
using namespace std;

class ComputerPart {

private:
	string type;
	int price;
	string name;

protected:
	virtual void setPrice(int price);
	virtual void setName(string name);
	virtual void setType(string type);

public:
	virtual int getPrice();
	virtual string getName();
	virtual string getType();
};