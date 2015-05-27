#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Display: public ComputerPart, public HasButtons{

	Display(int, char*, int);
};