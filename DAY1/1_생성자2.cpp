// protected ������ : �ڽ��� ��ü�� ����� ������(�߻��� ����)
//					  �Ļ� Ŭ������ ��ü�� ����� �ְ� �ϴ� ������ ���

class Animal
{
protected:
	Animal() {}
};
class Dog : public Animal
{
public: 
	Dog() {}   // Dog() : Animal() {}
};
int main()
{
	// ������ ������ ��� ��� ������
	Animal a;	// 1 error
	Dog    d;	// 2 ok
}



