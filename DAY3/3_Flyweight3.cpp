// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class Factory;
};

// Image 객체를 생성/관리하는 클래스
class Factory
{
	MAKE_SINGLETON(Factory)

	std::map<std::string, Image*> image_map;
public:
	Image* CreateImage(const std::string& url)
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
	Factory& factory = Factory::getInstance();

	Image* img1 = factory.CreateImage("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.CreateImage("www.naver.com/a.png");
	img2->Draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;
}



