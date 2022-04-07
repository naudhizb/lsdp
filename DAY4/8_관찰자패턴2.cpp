//1_����������1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};
// ������������ �⺻ ������ �����ϴ� ��� Ŭ���� ����
// ������ ����� ���� "Subject" ��� �մϴ�
class Subject
{
	vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};
// �پ��� ���̺�(������ ���)�� ���鶧  Subject�� ���� �Ļ��Ǹ� �˴ϴ�.
class Table : public Subject
{
	int value; 
public:
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





