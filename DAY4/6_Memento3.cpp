// 8_메멘토 - 178
#include <iostream>
#include <map>
#include <vector>
#include <functional>
using namespace std;


// 아래 같이 생각해서 Graphics 를 확장해 보세요
// 단, Token이 참조계수로 관리 되어야 합니다.
class Token
{
	int key;
	std::function<void(int)> func;
public:
	Token(int k, std::function<void(int)> f) : key(k), func(f) {}

	~Token() { func(key); }

	int get_key() const { return key; }
};


// 객체의 캡슐화를 위배 하지 않으면서
// 객체의 상태를 저장했다가 나중에 복구 할수 있도록 한다.
class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	struct Memento
	{
		int penWidth;
		int penColor;
		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};

	std::map<int, Memento*> state_map;
public:
	int Save()
	{
		static int key = 0;
		++key;
		Memento* p = new Memento(penWidth, penColor);
		state_map[key] = p;

		return key;
	}
	void Restore(int token)
	{
		penColor = state_map[token]->penColor;
		penWidth = state_map[token]->penWidth;
	}
	void delete_memento(int key)
	{

	}

	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);
	int token = g.Save(); // 객체의 상태를 저장했다가, 나중에 복구할수 있게 하자.
						  // "memento"

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);
}









