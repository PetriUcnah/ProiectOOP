#pragma once

class ComputerPart{

private:
	int price;
	char * name;

protected:
	virtual void setPrice(int price);
	virtual void setName(char *name);

public:
	virtual int getPrice();
	virtual char * getName();
};