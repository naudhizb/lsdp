#include <iostream>
#include <list>
#include <vector>
using namespace std;


// 모든 방문자의 인터페이스
template<typename T> struct IVisitor
{
	// 모든 방문자는 요소 한개를 방문할수 있다.(visit 함수로 요소를 받는다는것)
	virtual void Visit(T& e) = 0; // 참조 또는 포인터
	virtual ~IVisitor() {}
};

// 모든 복합객체는 방문자를 받아들여야 한다.
template<typename T> struct IAcceptor
{
	virtual void Accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

//-----------------------
// STL List 를 확장해서 방문자 패턴을 지원하도록 변경
template<typename T> 
class List : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // 생성자 상속

	// 아래 구현이 방문자 패턴의 핵심입니다. 
	void Accept(IVisitor<T>* v) override 
	{
		for (auto& e : *this) // 잘 생각해 보세요
			v->Visit(e);
	}
};
//---------------------------------------------------
// 이제 다양한 방문자를 만들면 됩니다.
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





