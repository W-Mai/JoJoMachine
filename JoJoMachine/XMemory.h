#pragma once
#include <vector>

template<typename Elem>
class XMemory {
	typedef std::vector<Elem> MemListType;
	MemListType mem;
	int currentIndex = 0;
	int MAX = 0;

	void adjustSize();
public:
	XMemory(int len = 0);
	void loadMem(MemListType list);
	Elem getNode(int index);
	void modifyCurrentNode(Elem data);
	int setCurrentIndex(int index);
	int getCurrentIndex() const;
	void expand(XMemory mem);
	void initWithNull(int n);
	void attendWithNull(int n);
	MemListType getAllNodes();
};

class XMemBar {
	typedef int8_t MemElemType;
	
	XMemory<MemElemType> mem;
public:
	XMemBar(int length);
	void modifyNode(MemElemType data);
	MemElemType getNode();
	XMemory<MemElemType> getAllNodes();
	int index();
	int jump(int index);
	int rear();
	int next();
};

class XCodes {
	typedef wchar_t CodesElemType;

	XMemory<CodesElemType> mem;
public:
	void loadCodes(std::vector<CodesElemType> codes);
	CodesElemType getCode();
	auto getCodes();
	int index();
	int jump(int index);
	int next();
};

template <typename Elem>
void XMemory<Elem>::adjustSize() {
	MAX = mem.size();
}

template <typename Elem>
XMemory<Elem>::XMemory(int len) {
	MAX = len;
	initWithNull(MAX);
}

template <typename Elem>
void XMemory<Elem>::loadMem(MemListType list) {
	mem = list;
	adjustSize();
}

template <typename Elem>
Elem XMemory<Elem>::getNode(int index) {
	if (index > MAX - 1) {
		throw "Out of index";
	}
	return mem[index];
}

template <typename Elem>
void XMemory<Elem>::modifyCurrentNode(Elem data) {
	mem[currentIndex] = data;
}

template <typename Elem>
int XMemory<Elem>::setCurrentIndex(int index) {
	if (index > MAX -1) {
		return MAX;
	}
	return currentIndex = index;
}

template <typename Elem>
int XMemory<Elem>::getCurrentIndex() const {
	return currentIndex;
}

template <typename Elem>
void XMemory<Elem>::expand(XMemory mem) {
	this->mem += mem;
}

template <typename Elem>
void XMemory<Elem>::initWithNull(int n) {
	mem.resize(n, 0);
	adjustSize();
}

template <typename Elem>
void XMemory<Elem>::attendWithNull(int n) {
	mem.resize(MAX + n);
	adjustSize();
}

template <typename Elem>
typename XMemory<Elem>::MemListType XMemory<Elem>::getAllNodes() {
	return mem;
}

inline void XMemBar::modifyNode(MemElemType data) {
	mem.modifyCurrentNode(data);
}
inline XMemBar::MemElemType XMemBar::getNode() {
	return mem.getNode(mem.getCurrentIndex());
}
inline XMemory<XMemBar::MemElemType> XMemBar::getAllNodes() {
	return mem;
}
inline int XMemBar::index() {
	return mem.getCurrentIndex();
}
inline int XMemBar::jump(int index) {
	return mem.setCurrentIndex(index);
}
inline int XMemBar::rear() {
	return mem.setCurrentIndex(mem.getCurrentIndex() - 1);
}
inline int XMemBar::next() {
	return mem.setCurrentIndex(mem.getCurrentIndex() + 1);
}
inline void XCodes::loadCodes(std::vector<CodesElemType> codes) {
	mem.loadMem(codes);
}
inline XCodes::CodesElemType XCodes::getCode() {
	return mem.getNode(mem.getCurrentIndex());

}
inline auto XCodes::getCodes() {
	return mem.getAllNodes();
}
inline int XCodes::index() {
	return mem.getCurrentIndex();
}
inline int XCodes::jump(int index) {
	return mem.setCurrentIndex(index);
}
inline int XCodes::next() {
	return mem.setCurrentIndex(mem.getCurrentIndex() + 1);
}
