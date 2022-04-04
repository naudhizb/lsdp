#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


// validation 정책은 사용자가 변경할수 있게 디자인 되어야 한다.

class Edit
{
	string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드안에 있는 변해야 하는 부분을 찾아라!
	// => 변해야 하는 코드를 가상함수로 분리한다.
	virtual bool validate(char c)
	{
		return true;
	}



	string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

			if ( validate(c) )  // 값의 유효성을 확인하는 가상함수호출
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;

		return data;
	}
};
// 이제 Validation 정책을 변경하려면 "Edit"의 파생클래스를 설계해서
// validate() 가상함수를 재정의하면 됩니다.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		cout << e.getData() << endl;
	}
}


