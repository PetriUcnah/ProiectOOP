#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Mouse: public ComputerPart, public HasButtons{
public:
	Mouse(int, string, int);
};