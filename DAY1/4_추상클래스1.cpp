// 1_�߻�Ŭ����1.cpp - 10page
// �߻�Ŭ���� : ���� �����Լ��� �Ѱ� �̻��ִ� Ŭ����.
// �ǵ� : �Ļ� Ŭ������ Ư�� �Լ��� �ݵ�� ������ �����ϴ� ��
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ�(pure virtual function)	
							// ������ ����.
};

class Rect : public Shape
{
	// Draw() �� ������ �������� ������ "�߻� Ŭ����"
	//                  �����ϸ� �߻�Ŭ���� �ƴ�.
};

int main()
{
	Shape s; // error. ��ü�� ����� ����.
	Shape* p; // ok. ������ ������ ����.
	Rect  r;
}
