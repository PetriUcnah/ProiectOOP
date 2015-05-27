#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Display: public ComputerPart, public HasButtons{
public:
	Display(int, string, int);
};