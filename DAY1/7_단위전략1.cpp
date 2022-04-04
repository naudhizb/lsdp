// list 앞에 넣는 코드는 변하지 않는다..
// 그런데, 동기화 여부를 변경할수 있게 하는 것이 좋다
// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로
// 2. 변하는 것을 다른 클래스로
template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//......
		unlock();
	}
};

List<int> st; // 전역변수는 멀티스레드에 안전하지 않습니다.

int main()
{
	st.push_front(10);
}




