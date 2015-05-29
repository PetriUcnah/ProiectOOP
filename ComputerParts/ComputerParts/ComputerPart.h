#pragma once
#include <string>
using namespace std;

class ComputerPart {

private:
	char* name;
	char* type;
	int price;

protected:
	virtual void setPrice(int price);
	virtual void setName(char* name);
	virtual void setType(char* type);

public:
	virtual bool hasMemory() = 0;
	virtual bool hasButtons() = 0;
	virtual int getPrice();
	virtual char* getName();
	virtual char* getType();
};