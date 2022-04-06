#include <iostream>

// iterator ���� 

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};
//-----------------------------------------------
// ��� ������ �ݺ��ڴ� ������ �����ؾ� �Ѵ�.
// �������̽� �ʿ�
template<typename T> struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual T GetObject() = 0;
	virtual ~IEnumerator() {}
};

// ��� �����̳ʴ� �ݺ��ڸ� ������ �־�� �Ѵ�.
// �����̳��� �������̽�
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};
//=============================
// slist �� ��Ҹ� ����ų�� �ִ� �ݺ��� �����
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

//slist_enumerator<int> p(100����)
//int n = p.GetObject();
//p.MoveNext();







// ��� �����̳ʴ� �ݺ��ڸ� ������ �־�� �Ѵ�.
template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IEnumerator<T>* GetEnumerator() override
	{
		return new slist_enumerator<T>(head); // ó���� ����Ű���� �ʱ�ȭ�� �ݺ���
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