#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"

class HDD: public ComputerPart, public HasMemory{
public:
	HDD(int, string, int, int);
};