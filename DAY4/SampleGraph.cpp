// SampleGraph.cpp
#include <iostream>
#include "IGraph.h"
using namespace std;

class SampleGraph : public IGraph
{
public:
	void Update(int n) override
	{
		cout << "Sample Graph : ";

		for (int i = 0; i < n; i++)
			cout << "*";

		cout << endl;
	}
};

// �÷����� ����ڴ� �÷����� Ŭ������ �̸��� ������ ���մϴ�.
// DLL�ȿ� ��ü�� �����ϴ� ��ӵ� �Լ� ����
extern "C" __declspec(dllexport)
IGraph* CreatePlugIn()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp /LD 

