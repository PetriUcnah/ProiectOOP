#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Keyboard : public ComputerPart, public HasButtons{
public:
	Keyboard(int, char*, int);
	bool hasMemory();
	bool hasButtons();
};