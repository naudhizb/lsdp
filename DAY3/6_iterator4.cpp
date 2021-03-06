#include <iostream>

// iterator 패턴 

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};


template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	inline T operator*() { return current->data; }

	inline slist_iterator& operator++()
	{
		current = current->next;

		return *this;
	}
};





template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	// 모든 컨테이너 설계자는 자신의 반복자 이름을 
	// iterator라는 약속된 형태로 외부에 알려야 한다.
	typedef slist_iterator<T> iterator;

	//slist_iterator<T> begin() { return slist_iterator<T>(head); }

	iterator begin() { return iterator(head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	
//	slist_iterator<int> p = s.begin();

	slist<int>::iterator p = s.begin();

	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;

}
