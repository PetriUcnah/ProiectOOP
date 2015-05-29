#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"

class HDD: public ComputerPart, public HasMemory{
public:
	HDD(int, char*, int, int);
	bool hasMemory();
	bool hasButtons();
};