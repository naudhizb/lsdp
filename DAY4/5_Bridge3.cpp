#include <iostream>
using namespace std;

struct ISharedMemory
{
	virtual void* Alloc() = 0;
	virtual void Free() = 0;
};

class Win32SharedMemory : public ISharedMemory
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};

class LinuxSharedMemory : public ISharedMemory 
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};

// 아래 처럼 하면
// 자료구조 5개를 2개 OS용으로 하면 10개 필요
/*
class Stack : public LinuxSharedMemory
{
	// Alloc, Free
};
class List : public LinuxSharedMemory
{
	// Alloc, Free
};
*/
// SharedMemory의 추상층 제공
class SharedMemory : public ISharedMemory
{
	ISharedMemory* pImpl;
public:
	void setImplementation(ISharedMemory* p) { pImpl = p; }
	void Alloc() { pIpml->Alloc(); }
	void Free() { pIpml->Free(); }
};
class List : public SharedMemory
{
};
class Stack : public SharedMemory
{
};
