#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Keyboard : public ComputerPart, virtual HasButtons{
public:
	Keyboard(int, string, int);
};