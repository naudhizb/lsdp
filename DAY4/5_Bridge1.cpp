// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// DIP ( Dependency Inversion Principle )
// 상위레벨(사용자, People) 은
// 하위레벨(제품, IPod) 을 사용할때
// 추상화에 의존해야 한다.

// => 관찰자를 DIP로 해석하는 경우도 있습니다.

// OCP와 거의 유사.. 변경가능하고, 교체 할수 있다.




// 모든 MP3제품의 인터페이스
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


