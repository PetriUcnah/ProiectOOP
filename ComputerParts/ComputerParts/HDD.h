#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"

class HDD: public ComputerPart, virtual HasMemory{
public:
	HDD(int, string, int, int);
};