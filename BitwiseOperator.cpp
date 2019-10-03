#include <iostream>

int main()
{
	int a = 0;
	while (true)
	{
		std::cin >> a;
		if (a & 2)
			std::cout << (a & 2) << "\tFM is enabled.\n";
		else
			std::cout << (a & 2) << "\tFM is disabled.\n";
	}
	system("pause");
}