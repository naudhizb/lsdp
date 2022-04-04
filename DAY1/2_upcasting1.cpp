// upcasting1.cpp
class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog*    p1 = &d; // ok
	int*    p2 = &d; // error
	Animal* p3 = &d; // ok. upcasting
					 // ��� Ŭ���� �����ͷ� �Ļ�Ŭ���� ��ü��
					// ����ų�� �ִ�.

	// �ٽ� 1. ��� Ŭ���� �����ͷ� �Ļ� Ŭ���� ����ų�� �ִ�.

	// �ٽ� 2. ��� Ŭ���� �����ͷδ� ��� Ŭ������ ���� �������� ����� ���ٰ���
	//			 �Ļ� Ŭ����(Dog)�� ���� ��� ���� �ȵ�..
	p3->age = 10;   // ok
	p3->color = 20; // error

	// �ٽ� 3. �Ļ�Ŭ���� ���� ����� �����Ϸ��� �Ļ� Ŭ���� �����ͷ� ĳ�����ؾ� �Ѵ�.
	static_cast<Dog*>(p3)->color = 10; // ��, �� ��� p3�� Dog ��ü�� ����Ų�ٴ�
										// Ȯ���� �־�� �Ѵ�.
}











