// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// DIP ( Dependency Inversion Principle )
// ��������(�����, People) ��
// ��������(��ǰ, IPod) �� ����Ҷ�
// �߻�ȭ�� �����ؾ� �Ѵ�.

// => �����ڸ� DIP�� �ؼ��ϴ� ��쵵 �ֽ��ϴ�.

// OCP�� ���� ����.. ���氡���ϰ�, ��ü �Ҽ� �ִ�.




// ��� MP3��ǰ�� �������̽�
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void Play() { cout << "Play MP3 with IPod" << endl; }
	void Stop() { cout << "Stop" << endl; }
};

class People
{
public:
	void Use(IMP3* p)
	{
		p->Play();
		p->Stop();
	}
};
int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


