// ICalc2.h
#pragma once

struct IRefCount 
{
	// 참조계수로 관리한다면
	// 참조계수 함수도 인터페이스에 있어야 합니다.
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};
struct ICalc : public IRefCount
{

	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}

}; 
