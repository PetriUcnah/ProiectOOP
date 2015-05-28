#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Mouse: public ComputerPart, virtual HasButtons{
public:
	Mouse(int, string, int);
};