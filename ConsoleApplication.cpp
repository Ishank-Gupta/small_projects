#include <iostream>

void func(void);

static int count = 10;

int main()
{
	while (count--)
	{
		func();
	}
	system("pause");
}

void func(void)
{
	static int i = 5;
	i++;
	std::cout << "i is " << i << std::endl;
	std::cout << "count is " << count << std::endl;
}