#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� �и��ϴ�.
// 2. ���ϴ� ���� �ٸ� Ŭ������ �и��Ѵ�.

// Validation ��å�� ���� Ŭ������ ��ü �����ؾ� �Ѵ�.
// �������̽� ����� ���� ����!!!
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


