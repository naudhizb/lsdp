// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};

class Derived : public Base
{
public:
	// �����Լ� �����ǽ� ��Ÿ�߻�.. 
	// => ������ �ƴ϶�, �ٸ� �Լ��� ó��
	// => �׷��� C++11 ���ʹ� "override" �� ���̶�� ����
	virtual void fooo()  override {}
	virtual void goo(double) override {}
};
int main()
{
}




