#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"
#include "HasButtons.h"

class ExternalHDD : public ComputerPart, virtual HasMemory, virtual HasButtons{
public:
	ExternalHDD(int, int, int, int,string);
};