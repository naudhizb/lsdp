//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>
using namespace std;



// 모든 그래프의 인터페이스
struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};




class Table
{
	vector<IGraph*> v;
	int value; // table 의 data 값
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->Update(data);
	}
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

int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	t.edit();
}





