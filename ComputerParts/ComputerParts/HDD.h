#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"

class HDD: public ComputerPart, public HasMemory{

	HDD(int, char*, int, int);
};