#pragma once

class HasButtons {
private:
	int numOfButtons;

protected:
	int getNum(){ return numOfButtons; }
	void setNumOfButtons(int num){ numOfButtons = num; }

public:
	virtual int getNumOfButtons() {
		return numOfButtons;
	}
};