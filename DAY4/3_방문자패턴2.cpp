#include <iostream>
#include <list>
#include <vector>
using namespace std;


// ��� �湮���� �������̽�
template<typename T> struct IVisitor
{
	// ��� �湮�ڴ� ��� �Ѱ��� �湮�Ҽ� �ִ�.(visit �Լ��� ��Ҹ� �޴´ٴ°�)
	virtual void Visit(T& e) = 0; // ���� �Ǵ� ������
	virtual ~IVisitor() {}
};

// ��� ���հ�ü�� �湮�ڸ� �޾Ƶ鿩�� �Ѵ�.
template<typename T> struct IAcceptor
{
	virtual void Accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

//-----------------------
// STL List �� Ȯ���ؼ� �湮�� ������ �����ϵ��� ����
template<typename T> 
class List : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // ������ ���

	// �Ʒ� ������ �湮�� ������ �ٽ��Դϴ�. 
	void Accept(IVisitor<T>* v) override 
	{
		for (auto& e : *this) // �� ������ ������
			v->Visit(e);
	}
};
//---------------------------------------------------
// ���� �پ��� �湮�ڸ� ����� �˴ϴ�.
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	void Visit(T& e) override { e *= 2; }
};
template<typename T> class ZeroVisitor : public IVisitor<T>
{
public:
	void Visit(T& e) override { e = 0; }
};

int main()
{
	List<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.Accept(&tv); 

	ZeroVisitor<int> zv;
	s.Accept(&zv);
}





