// 8_메멘토 - 178
#include <iostream>
#include <map>
#include <vector>
using namespace std;

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









