// 동기화 여부를 전략패턴으로 분리해 보자
// 객체지향 디자인에서는 널리 사용되는 모양인데..
// C++에서는 "가상함수호출"의 오버헤드 문제가 있다.
// 자주 사용되는 경우는 성능의 문제가 있다.
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

template<typename T> class List
{
	ISync* pSync;
public:
	void setSync(ISync* p) { pSync = p; }
	void push_front(const T& a)
	{
		pSync->lock();
		//......
		pSync->unlock();
	}
};

List<int> st; 

int main()
{
	st.push_front(10);
}




