#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// �پ��� Stream Ŭ������ ������ ���Ͻ�����.
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
		std::cout << buff << " ����" << std::endl;
	}
};

int main()
{
//	FILE* f = fopen("a.txt", "wt");
//	fclose(f);

	// ������ ���� Ŭ����
	FileStream fs("a.txt");
	fs.Write("Hello");

//	NetworkStream ns("127.0.0.1", 4000);
//	ns.Write("Hello");

//	PipeStream ps("NamedPipe");
//	ps.Write("Hello");
}