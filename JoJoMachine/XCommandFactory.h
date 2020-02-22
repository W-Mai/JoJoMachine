#pragma once
#include <string>
#include <map>
#include "XCommands.h"

class XCommandFactory {
	std::map<std::string, CommandBase> commands;
public:
	bool addCommand(CommandBase cmd) {
		if (commands.find(cmd.getName()) != commands.end()) {
			return false;
		}
		commands[cmd.getName()] = cmd;
		return true;
	}
	CommandBase& getCommand(const std::string& cmd) {
		return commands[cmd];
	}
	std::map<std::string, CommandBase>& getAllCommands() {
		return commands;
	}
};

