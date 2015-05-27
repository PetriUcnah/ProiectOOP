#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Keyboard : public ComputerPart, public HasButtons{
	Keyboard(int, char*, int);
};