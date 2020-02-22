#include <iostream>
#include "XCommandFactory.h"
#include <algorithm>
#include "XParser.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	XCommandFactory commandFactory;
	vector<CommandBase> cmdList = { Cmd÷Ï(), Cmd÷Ì() };
	
	for_each(cmdList.begin(), cmdList.end(), [&](const auto& x) {
		commandFactory.addCommand(x);
	});
	
	auto all = commandFactory.getAllCommands();

	for(auto x:all) {
		cout << x.second.getName() << endl;
	}

	const auto codes = L""
			"  "       "  "
		  "÷Ï÷Ï÷Ï÷Ï    ÷Ï÷Ï÷Ï÷Ï"
		 "ÕÙ√®  ÷Ï÷Ï  ÷Ï÷Ï  ÕÙ√®"
		"÷Ï÷Ï√®÷Ï÷Ï÷Ï√®÷Ï÷Ï÷Ï√®÷Ïπ∑"
		"π∑π∑π∑÷Ìﬂ˜√®÷Ï√®÷Ï√®÷Ì√®√®"
		"÷ÏÕÙπ∑    ﬂ˜π∑÷Ì    ﬂ˜√®"
		"√®∫ﬂ√®÷Ì  ÷Ì÷Ì∫ﬂ÷Ï  ÷Ï÷Ï÷Ï"
		"÷Ï÷Ï÷Ï∫ﬂ∫ﬂ÷Ï÷Ï÷Ï∫ﬂ√®√®∫ﬂπ∑"
		"÷Ì∫ﬂπ∑∫ﬂ÷Ï ÷Ï÷Ï ∫ﬂ÷Ì÷Ì÷Ì÷Ì"
		  "÷Ì÷Ì∫ﬂ÷Ì÷Ì÷Ì÷Ì÷Ì÷Ì÷Ì÷Ì"
		   "∫ﬂ√®√®÷Ï∫ﬂ√®÷Ï÷Ï∫ﬂ"
			 """""""""""";
	
	XParser ps(commandFactory);
	auto res = ps.getCodes(codes);
	for (int i = 0; i<res.getCodes().size();i++) {
		wcout << res.getCode() << endl;
		res.next();
	}
	
	
	return 0;
}