#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 분리하다.
// 2. 변하는 것을 다른 클래스로 분리한다.

// Validation 정책을 담은 클래스는 교체 가능해야 한다.
// 인터페이스 기반의 약한 결합!!!
struct IValidator
{
	virtual bool validate(const string& data, char c) = 0;
	virtual bool iscomplete(const string& data) { return true; }
	virtual ~IValidator() {}
};
//주민등록번호 : 901    1     확인

class Edit
{
	string data;
	//--------------------------------------------
	IValidator* pVal;
public:
	Edit() : pVal(0) {}
	void setValidator(IValidator* p) { pVal = p; }
	//-----------------------------------------------
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pVal == 0 || pVal->iscomplete(data))) break;

			if (pVal == 0 || pVal->validate(data, c)) //유효성 확인을 다른클래스에 위임(delegate)
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;

		return data;
	}
};

// 이제 입력값을 Validation 할수 있는 다양한 클래스를 제공하면 됩니다.

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	bool validate(const string& data, char c) override
	{
		return data.size() < value && isdigit(c);
	}

	bool iscomplete(const string& data) override
	{
		return data.size() == value;
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v); // 유효성 확인을 위한 객체 전달

	while (1)
	{
		cout << e.getData() << endl;
	}
}


