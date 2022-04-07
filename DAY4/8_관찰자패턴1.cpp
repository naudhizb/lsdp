//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


// 관찰자(Observer) 
// 객체간의 1 : N 의 관계를 설정하고
// 객체(1)이 변경되었을때 등록된 모든 객체들에게 통보한다.





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
			cin >> value; // 데이타가 수정되었으므로
			notify(value); // 모든 그래프에 알려준다.
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





