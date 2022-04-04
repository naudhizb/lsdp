#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Edit
{
	string data;
public:
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (isdigit(c))
			{
				cout << c ;
				data.push_back(c);
			}
		}
		cout << endl;
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		cout << e.getData() << endl;
	}
}


