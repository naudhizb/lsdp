#include <iostream>

// iterator 패턴 

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};
//-----------------------------------------------
// 모든 종류의 반복자는 사용법이 동일해야 한다.
// 인터페이스 필요
template<typename T> struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual T GetObject() = 0;
	virtual ~IEnumerator() {}
};

// 모든 컨테이너는 반복자를 꺼낼수 있어야 한다.
// 컨테이너의 인터페이스
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};
//=============================
// slist 의 요소를 가리킬수 있는 반복자 만들기
template<typename T> class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = 0) : current(p) {}

	T GetObject() override { return current->data; }

	bool MoveNext() override
	{
		current = current->next;
		
		return current;
	}
};

//slist_enumerator<int> p(100번지)
//int n = p.GetObject();
//p.MoveNext();







// 모든 컨테이너는 반복자를 꺼낼수 있어야 한다.
template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IEnumerator<T>* GetEnumerator() override
	{
		return new slist_enumerator<T>(head); // 처음을 가리키도록 초기화된 반복자
	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IEnumerator<int>* p = s.GetEnumerator();

	std::cout << p->GetObject() << std::endl;
	p->MoveNext();
	std::cout << p->GetObject() << std::endl;

}