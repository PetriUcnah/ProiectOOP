#pragma once


class HasMemory{

private:
	int capacity;
	int frequency;

protected:
	int getCap() { return capacity; }
	int getFreq() { return frequency; }
	void setMemory(int capacity, int frequency) { this->capacity = capacity; this->frequency = frequency; }

public:
	virtual int getCapacity(){ return capacity; }
	virtual int getFrequency(){ return frequency; }
};