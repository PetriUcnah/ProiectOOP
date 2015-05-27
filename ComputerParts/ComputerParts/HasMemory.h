#pragma once


class HasMemory{

private:
	int capacity;
	int frequency;

protected:
	virtual void setMemory(int capacity, int frequency);

public:
	virtual int getCapacity();
	virtual int getFrequency();
};