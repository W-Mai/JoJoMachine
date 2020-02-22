#pragma once
#include <string>
#include "XMemory.h"

class CommandBase {
	std::string name;

public:
	CommandBase() {
		name = "CommandBase";
	}
	virtual std::string getName() {
		return name;
	}
	virtual int operate(XMemBar memory, XCodes codes) { return 0; };
};

class Cmd÷Ï {
public:
	
};
