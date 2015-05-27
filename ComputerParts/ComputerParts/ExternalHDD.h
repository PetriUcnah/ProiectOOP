#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"
#include "HasButtons.h"

class ExternalHDD : public ComputerPart, public HasMemory, public HasButtons{

	ExternalHDD(int, char*, int, int, int);
};