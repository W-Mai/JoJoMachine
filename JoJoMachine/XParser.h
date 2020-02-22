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
		std::vector<wchar_t> resString;
		for (const auto& x:content) {
			if (!iswspace(x)) {
				resString.push_back(x);
			}
		}
		rtn.loadCodes(resString);
		return rtn;
	}
};

