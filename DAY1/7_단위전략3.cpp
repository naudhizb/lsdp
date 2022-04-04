// 변하는 것의 분리
// 1. 가상함수로 분리 - "template method"

// 2. 다른 클래스로 분리
//    => 정책 클래스를 어떻게 교체 가능하게 할것인가 ?

//	  A. 인터페이스를 설계 해서 교체 - strategy 패턴

//	  B. 정책클래스를 템플릿 인자로 교체 - Policy Base Design(단위전략), 
//											C++에서 아주널리사용

//					인터페이스 교체			템플릿 교체
//	속도			느리다					빠르다(인라인 치환)
//  실행시간 교체	가능					템플릿 인자이므로 실행할때는 교체 못함
//					edit.setValidator(&v)

// 아래 코드에서 동기화 정책을 담은 클래스가 지켜야 하는 규칙이 생긴다.
// "lock/unlock" 이 있어야 한다.
// => "인터페이스 처럼 코드로 표현 안됨"
// => 문서화 해야 한다. 
// => "cppreference.com"







#include <iostream>

template<typename T, typename ThreadModel  = NoLock > class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//......
		tm.unlock();
	}
};
// List의 동기화 정책으로 전달될 클래스
struct MutexLock
{
	// pthread_mutex_t handle
	inline void lock() { std::cout << "mutex lock" << std::endl; }
	inline void unlock() { std::cout << "mutex unlock" << std::endl; }
};
struct NoLock
{
	inline void lock() {  }
	inline void unlock() { }
};
//----------------------------
//List<int, NoLock> st; 
//List<int, MutexLock> st;
List<int> st;

int main()
{
	st.push_front(10);
}




