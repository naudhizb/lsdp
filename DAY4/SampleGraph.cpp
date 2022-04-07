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

// 플러그인 사용자는 플러그인 클래스의 이름을 알지는 못합니다.
// DLL안에 객체를 생성하는 약속된 함수 제공
extern "C" __declspec(dllexport)
IGraph* CreatePlugIn()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp /LD 

