#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"
#include "HasButtons.h"

class ExternalHDD : public ComputerPart, public HasMemory, public HasButtons{
public:
	ExternalHDD(int, int, int, int, char*);
	bool hasMemory();
	bool hasButtons();
};