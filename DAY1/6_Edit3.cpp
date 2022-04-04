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

			if (c == 13) break;

			if (isdigit(c))
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;

		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		cout << e.getData() << endl;
	}
}


