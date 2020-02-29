// CloseLater.h

#pragma once

template <void closeFunc(void*)>
class CloseLater {
public:
	CloseLater(void* ptr) : _ptr(ptr) { }
	~CloseLater() {
		closeFunc(_ptr);
	}
private:
	void* _ptr;
};
