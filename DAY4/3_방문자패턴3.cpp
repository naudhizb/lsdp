// 방문자 패턴의 의미!!
class Shape 
{
	virtual void Draw() = 0;
};
class Rect   : public Shape {};
class Circle : public Shape {};

// 전통적인 객체지향 디자인(다형성을 잘사용했다면)
// 클래스의 추가    :  쉽다
// 가상 함수의 추가 :  쉽지 않다(기반 클래스에 가상함수를 추가하면)
//					모든 파생 클래스에 재정의를 하는 일이 발생.


// 방문자 패턴으로 디자인 하면
MoveVisitor mv;
v.Accept(&mv);
// 클래스의 추가 : ?
// 가상 함수의 추가 : 쉽다. 가상함수가 할일을 방문자로 하면 된다. 




