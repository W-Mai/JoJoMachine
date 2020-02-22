#include <iostream>
#include "XCommandFactory.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	XCommandFactory commandFactory;
	commandFactory.addCommand(CommandBase());
	//auto c = commandFactory.getCommand("CommandBase");
	commandFactory.addCommand(CommandBase());
	auto all = commandFactory.getAllCommands();

	for(auto x:all) {
		cout << x.second.getName() << endl;

	}

	return 0;
}