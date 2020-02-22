#pragma once
#include "XCommandFactory.h"
#include <string>
#include <vector>

class XParser {
public:
	explicit XParser(const XCommandFactory &factory) {
		return;
	}
	XCodes getCodes(std::wstring content) {
		auto rtn = XCodes();
		rtn.loadCodes(std::vector<wchar_t>(content.begin(), content.end()));
		return rtn;
	}
};

