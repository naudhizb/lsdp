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


