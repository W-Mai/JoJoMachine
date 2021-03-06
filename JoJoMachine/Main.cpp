#include <iostream>
#include "XCommandFactory.h"
#include <algorithm>
#include "XParser.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	XCommandFactory commandFactory;
	vector<CommandBase> cmdList = { Cmd��(), Cmd��() };
	
	for_each(cmdList.begin(), cmdList.end(), [&](const auto& x) {
		commandFactory.addCommand(x);
	});
	
	auto all = commandFactory.getAllCommands();

	for(auto x:all) {
		cout << x.second.getName() << endl;
	}

	const auto codes = L""
			"  "       "  "
		  "��������    ��������"
		 "��è  ����  ����  ��è"
		"����è������è������è�칷"
		"����������è��è��è��èè"
		"������    ������    ��è"
		"è��è��  ��������  ������"
		"������ߺ��������èè�߹�"
		"���߹����� ���� ����������"
		  "����������������������"
		   "��èè���è�����"
			 """""""""""";
	
	XParser ps(commandFactory);
	auto res = ps.getCodes(codes);
	for (int i = 0; i<res.getCodes().size();i++) {
		wcout << res.getCode() << endl;
		res.next();
	}
	
	
	return 0;
}