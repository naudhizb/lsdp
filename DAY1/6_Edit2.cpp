#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


// validation ��å�� ����ڰ� �����Ҽ� �ְ� ������ �Ǿ�� �Ѵ�.

class Edit
{
	string data;
public:
	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ�ȿ� �ִ� ���ؾ� �ϴ� �κ��� ã�ƶ�!
	// => ���ؾ� �ϴ� �ڵ带 �����Լ��� �и��Ѵ�.
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


