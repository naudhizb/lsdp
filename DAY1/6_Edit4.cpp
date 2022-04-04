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
//�ֹε�Ϲ�ȣ : 901    1     Ȯ��

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

			if (pVal == 0 || pVal->validate(data, c)) //��ȿ�� Ȯ���� �ٸ�Ŭ������ ����(delegate)
			{
				cout << c;
				data.push_back(c);
			}
		}
		cout << endl;

		return data;
	}
};

// ���� �Է°��� Validation �Ҽ� �ִ� �پ��� Ŭ������ �����ϸ� �˴ϴ�.

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
	e.setValidator(&v); // ��ȿ�� Ȯ���� ���� ��ü ����

	while (1)
	{
		cout << e.getData() << endl;
	}
}


