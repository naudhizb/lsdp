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
		std::cout << buff << " ����" << std::endl;
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");


	// ���Ͽ� ����, �����ؼ� ���� ����� �ʿ��ϴ�.

	// 1. data�� �����ϰ�, ����.

	// 2. FileStream �� zipWrite() ��� �Լ��� �߰�����. - 
	//   => NetwrokStream, PipieStream ���� �߰��ؾ� �Ѵ�.

	// 3. ������ ��� Ŭ���� Stream�� �߰�����.
	//  => ���ο� ���� �ʿ� �Ҷ����� �߰��ؾ� �Ѵٸ�?? OCP�� �����Ҽ� ����.
	//  =>���Ͽ� ����, ��ȣȭ�ؼ� ���� ����� �ʿ��ϴ�.

	ZipDecorator zd(&fs);

	zd.Write("Hello"); // 1. ����Ÿ ���� ��� ����
						// 2. fs�� ���� ���(Write)�� ����� ����Ÿ ����.
}