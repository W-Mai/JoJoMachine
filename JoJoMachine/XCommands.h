#pragma once
#include <string>
#include "XMemory.h"

class CommandBase {
protected:
	std::string name;

public:
	virtual ~CommandBase() = default;

	CommandBase() {
		name = "CommandBase";
	}
	virtual std::string getName() {
		return name;
	}
	virtual int operate(XMemBar* memory, XCodes codes) { return 0; };
};

class Cmd÷Ï:public CommandBase {
public:
	Cmd÷Ï() {
		name = "÷Ï";
	}

	int operate(XMemBar* memory, XCodes codes) override {
		memory[0].modifyNode(memory[0].getNode() + 1);
		return 1;
	}
};
class Cmd÷Ì:public CommandBase {
public:
	Cmd÷Ì() {
		name = "÷Ì";
	}

	int operate(XMemBar* memory, XCodes codes) override {
		memory[0].modifyNode(memory[0].getNode() - 1);
		return 1;
	}
};
