//1_����������1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


// ������(Observer) 
// ��ü���� 1 : N �� ���踦 �����ϰ�
// ��ü(1)�� ����Ǿ����� ��ϵ� ��� ��ü�鿡�� �뺸�Ѵ�.





// ��� �׷����� �������̽�
struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

class Table
{
	vector<IGraph*> v;
	int value; // table �� data ��
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// ��ϵ� ��� �׷����� �˷��ش�.
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			cout << "Data >>";
			cin >> value; // ����Ÿ�� �����Ǿ����Ƿ�
			notify(value); // ��� �׷����� �˷��ش�.
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





