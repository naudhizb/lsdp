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

// 요구사항이 많아진다면
// 사용자가 직접 IMP3를 사용하지 말고
// 중간층을 제공한다.(추상계층)

// Bridge : 구현과 추상(사용자가 사용하는 인터페이스)
//		을 분리해서 상호 독립적 update가 가능하게 한다.
class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p)
	{
		if (p == 0)
			impl = new IPod;
	}
	// 추상층에서는 구현계층을 다시 사용한다.
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


