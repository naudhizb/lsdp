// ������ ���� ( smkang @ codenuri.co.kr )
// github.com/codenuri/lsdp   ��  "DAY1_�����ҽ�.zip" ���� �ֽ��ϴ�.
// �޾� �μ���..

// 1. VC ���� ���� ������

// 2. x86, Debug �� ����

// 3. ������Ʈ�޴� - �Ӽ� �޴�����
//    Windows SDK ������ �÷��� ���� ���� ���� �ּ���.

// C++11 ���� ��� ����մϴ�.









//������1.cpp - 3page

class Base
{
public:
//	Base()     {} 
	Base(int a){} 
	~Base()    {} 
};
class Derived : public Base
{
public:
	// ����� �ڵ�     // �����Ϸ��� ������ �ڵ�					
//	Derived() {}       // Derived()      : Base() {} 
//	Derived(int a) {}  // Derived(int a) : Base() {}
	~Derived() {}      // ~Derived() {   .....;  ~Base(); }

	// ��� Ŭ������ ����Ʈ �����ڰ� ���°��
	// �ݵ�� �Ļ�Ŭ�������� ��������� ��� Ŭ���� �����ڸ� ȣ���ؾ� �մϴ�.
	Derived() : Base(0) {}      
	Derived(int a) : Base(a) {}  


};
int main()
{
	Derived d(1); // call Derived::Derived(int)
}