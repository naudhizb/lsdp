#include <iostream>
#include <mutex>

// github.com/aosp-mirror     // android open source project

// libutils/include/utils 에서 Singleton.h

// CRTP ( Curiosly Recurring Template Pattern )
// 기반 클래스가 템플릿 인데, 파생 클래스가 자신의 이름을 
// 기반 클래스 템플릿 인자로 전달하는 것

// 기반 클래스가 미래에 만들어질 파생 클래스 이름을 사용할수 있게 된다.

template<typename T> 
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;

	static T* pinstance;   // <<===
	static std::mutex mtx;
public:
	static T& getInstance()  // <==
	{
		std::lock_guard<std::mutex> lg(mtx);

		if (pinstance == 0)
			pinstance = new T; // <<==

		return *pinstance;
	}
};
template<typename T> T* Singleton<T>::pinstance = 0;
template<typename T> std::mutex Singleton<T>::mtx;


// 마우스도 힙에 만드는 Singleton 으로 하고 싶다.
class Mouse : public Singleton< Mouse  >
{

};
class Keyboard : public Singleton< Keyboard  >
{

};

int main()
{
	Mouse& c1 = Mouse::getInstance();
	Mouse& c2 = Mouse::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}




