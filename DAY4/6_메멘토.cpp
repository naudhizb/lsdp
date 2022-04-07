// 8_메멘토 - 178
#include <iostream>
using namespace std;

// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.
	// 1. 함수인자로 전달
	// Windows api 의 gdi+
	g.DrawLine(0, 0, 100, 100, red, 5);
	g.DrawLine(0, 0, 100, 100, blue, 10);

	// 2. graphics 객체의 속성으로 전달하자
	// osx, ios
	// windows의 gdi 도 유사
	g.SetStrokeColor(red);
	g.SetStrokeLineWidth(10);
	g.DrawLine(0, 0, 100, 100);
}








