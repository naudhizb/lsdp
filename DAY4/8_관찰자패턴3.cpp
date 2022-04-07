//1_����������1 - 94 page
#include <iostream>
#include <vector>
using namespace std;

class Subject;

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	Subject* pSubject; // �����Ǵ��(Table)�� ���� ������
};

class Subject
{
	vector<IGraph*> v;
public:
	void attach(IGraph* p)
	{ 
		v.push_back(p); 
		p->pSubject = this;
	}
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

class Table : public Subject
{
	int value;
	int data[5]{ 1,2,3,4,5 };

public:
	int* getData() { return data; }

	void edit()
	{
		while (1)
		{
			cout << "Data >>";
			cin >> value;
			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		// Table�� ����Ǿ����Ƿ�
		// �����ؼ� ����Ÿ�� �����´�.
		// ���� pSubject �� Subject* �Դϴ�.
		// �׷���, getData()�� Table ��� �Լ� �Դϴ�.
		//int* data = pSubject->getData();

		// �ᱹ getData�� ȣ���Ϸ���
		// Table*�� ĳ������ �ʿ� �մϴ�.
		Table* pTable = static_cast<Table*>(pSubject);

		int* data = pTable->getData();

		// ���� data�� ����ؼ� �׷��� �׸��� �˴ϴ�.
		
		printf("%d, %d, %d\n", data[0], data[1], data[2]);

		cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			cout << "*";

		cout << endl;
	}
};

class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			cout << ")";

		cout << endl;
	}
};
int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





