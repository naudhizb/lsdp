//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>
using namespace std;

class Subject;

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	Subject* pSubject; // 관찰의대상(Table)에 대한 포인터
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
		// Table이 변경되었으므로
		// 접근해서 데이타를 가져온다.
		// 현재 pSubject 는 Subject* 입니다.
		// 그런데, getData()는 Table 멤버 함수 입니다.
		//int* data = pSubject->getData();

		// 결국 getData를 호출하려면
		// Table*로 캐스팅이 필요 합니다.
		Table* pTable = static_cast<Table*>(pSubject);

		int* data = pTable->getData();

		// 이제 data를 사용해서 그래프 그리면 됩니다.
		
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





