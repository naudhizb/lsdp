// 8_�޸��� - 178
#include <iostream>
using namespace std;

// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.
	// 1. �Լ����ڷ� ����
	// Windows api �� gdi+
	g.DrawLine(0, 0, 100, 100, red, 5);
	g.DrawLine(0, 0, 100, 100, blue, 10);

	// 2. graphics ��ü�� �Ӽ����� ��������
	// osx, ios
	// windows�� gdi �� ����
	g.SetStrokeColor(red);
	g.SetStrokeLineWidth(10);
	g.DrawLine(0, 0, 100, 100);
}








