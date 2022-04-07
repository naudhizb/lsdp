#include <iostream>
#include <vector>

#define USING_GUI
#include "cppmaster.h"
using namespace std;


struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

class Subject
{
	vector<IGraph*> v;
public:
	Subject()
	{
		// 약속된 디렉토리에 있는 모든 DLL을 Load합니다.
		ec_enum_files("C:\\PLUGIN", "*.dll", loadGraph, this);
	}

	// callback 함수로 전달되는 함수는
	// 멤버 함수로 만들때 반드시 static 으로 해야 합니다.
	static int loadGraph(std::string filename, void* p)
	{
		Subject* pThis = static_cast<Subject*>(p);

		std::cout << "DLL 찾음 " << filename << std::endl;

		void* addr = ec_load_module(filename);

		typedef IGraph* (*F)();
		F f = (F)ec_get_function_address(addr, "CreatePlugIn");

		IGraph* g = f();

	//	attach(g); // error. static 멤버에서는 일반 멤버 호출안됨
		pThis->attach(g);

		return 1;
	}







	void attach(IGraph* p) { v.push_back(p); }
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





