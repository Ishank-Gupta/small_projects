#include <iostream>

#define private public

class test {
private:
	int num;
public:
	int count;
	test() :num(0), count(0) {}
	~test() {}
};

int main() 
{
	test obj;
	obj.count = 2;
	obj.num = 1;
	std::cout << "num = " << obj.num << std::endl;
	std::cout << "count = " << obj.count << std::endl;

	system("pause");
}