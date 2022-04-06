// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	static std::map<std::string, Image*> image_map;

	// Image ��ü �ڽ��� ����� �ִ� static ��� �Լ�
	static Image* Create(const std::string& url)
	{
		if (image_map[url] == 0)
		{
			image_map[url] = new Image(url);
		}
		return image_map[url];
	}
};

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



