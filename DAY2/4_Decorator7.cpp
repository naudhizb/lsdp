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
		std::cout << buff << " ����" << std::endl;
	}
};

// 1. Stream Ŭ������� ����߰� Ŭ������ ���� ��� Ŭ���� �̾���Ѵ�
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s)
	{
		std::string s2 = s + " ����";  // �߰��� ���(����Ÿ ����)
		stream->Write(s2); // ������ ��ɼ���
							// (����, ��Ʈ��ũ, ������)�� ����
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");

	ZipDecorator zd(&fs);
	zd.Write("Hello"); 
}