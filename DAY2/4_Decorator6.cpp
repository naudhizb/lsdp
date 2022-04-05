#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}
};


class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& buff)
	{
		std::cout << buff << " 쓰기" << std::endl;
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");


	// 파일에 쓸때, 압축해서 쓰는 기능이 필요하다.

	// 1. data를 압축하고, 쓰자.

	// 2. FileStream 에 zipWrite() 멤버 함수를 추가하자. - 
	//   => NetwrokStream, PipieStream 에도 추가해야 한다.

	// 3. 공통의 기반 클래스 Stream에 추가하자.
	//  => 새로운 것이 필요 할때마다 추가해야 한다면?? OCP를 만족할수 없다.
	//  =>파일에 쓸때, 암호화해서 쓰는 기능이 필요하다.

	ZipDecorator zd(&fs);

	zd.Write("Hello"); // 1. 데이타 압축 기능 수행
						// 2. fs의 원래 기능(Write)에 압축된 데이타 전달.
}