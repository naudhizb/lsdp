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

			if ( validate(c) )  // ���� ��ȿ���� Ȯ���ϴ� �����Լ�ȣ��
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;

		return data;
	}
};
// ���� Validation ��å�� �����Ϸ��� "Edit"�� �Ļ�Ŭ������ �����ؼ�
// validate() �����Լ��� �������ϸ� �˴ϴ�.
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


