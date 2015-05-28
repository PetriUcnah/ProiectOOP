#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Display: public ComputerPart, virtual HasButtons{
public:
	Display(int, string, int);
};