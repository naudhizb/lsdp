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

// �Ʒ� ó�� �ϸ�
// �ڷᱸ�� 5���� 2�� OS������ �ϸ� 10�� �ʿ�
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
// SharedMemory�� �߻��� ����
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
