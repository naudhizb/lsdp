// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;


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

// �䱸������ �������ٸ�
// ����ڰ� ���� IMP3�� ������� ����
// �߰����� �����Ѵ�.(�߻����)

// Bridge : ������ �߻�(����ڰ� ����ϴ� �������̽�)
//		�� �и��ؼ� ��ȣ ������ update�� �����ϰ� �Ѵ�.
class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p)
	{
		if (p == 0)
			impl = new IPod;
	}
	// �߻��������� ���������� �ٽ� ����Ѵ�.
	void Play() { impl->Play(); }
	void Stop() { impl->Stop(); }

	void PlayOneMinute()
	{
		impl->Play();
		//....
		impl->Stop();
	}
};

class People
{
public:
	void Use(MP3* p)
	{
		p->Play();
		p->Stop();
	}
};

int main()
{
	People p;
	MP3 mp3;
	p.Use(&mp3);
}


