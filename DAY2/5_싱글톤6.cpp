#include <iostream>
#include <mutex>



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




