#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Mouse: public ComputerPart, public HasButtons{

	Mouse(int, char*, int);
};