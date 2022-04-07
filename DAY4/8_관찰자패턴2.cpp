//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};
// 관찰자패턴의 기본 구조를 제공하는 기반 클래스 설계
// 관찰의 대상을 흔히 "Subject" 라고 합니다
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
// 다양한 테이블(관찰의 대상)을 만들때  Subject로 부터 파생되면 됩니다.
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





