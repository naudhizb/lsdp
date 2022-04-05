#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


struct Stream
{
	virtual void Write( const std::string& s) = 0;
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

	void Write( const std::string& buff)
	{
		std::cout << buff << " 쓰기" << std::endl;
	}
};

// 1. Stream 클래스들과 기능추가 클래스는 동일 기반 클래스 이어야한다
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s)
	{
		std::string s2 = s + " 압축";  // 추가할 기능(데이타 압축)
		stream->Write(s2); // 원래의 기능수행
							// (파일, 네트워크, 파이프)에 쓰기
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");

	ZipDecorator zd(&fs);
	zd.Write("Hello"); 
}