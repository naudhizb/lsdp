// 동기화 여부를 전략패턴으로 분리해 보자
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




