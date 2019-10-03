#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//void rotateSquareMatrix(int *arr, const int size) {
//
//	std::cout << "\n\n";
//	int i, j, num;
//	std::vector<int> row(size);
//	//
//
//	//
//	for (i = 0; i < size; i++)
//	{
//		for (j = 0; j < size; j++)
//			std::cout << *((arr + i*size) + j) << "\t";
//		std::cout << std::endl;
//	}
//}
//
//int main()
//{
//	int a[4][4] = { {1,2,3,4}, {2,3,4,1}, {3,4,1,2}, {4,1,2,3} };
//	//
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//			std::cout << a[i][j] << "\t";
//		std::cout << std::endl;
//	}
//	//
//	rotateSquareMatrix((int *)a, 4);
//	//
//	system("pause");
//}

//int main()
//{
//	unsigned char *p = nullptr;
//	unsigned int *i;
//	*i = 123456;
//	//
//	std::cout << sizeof(p) << std::endl;
//	std::cout << sizeof(i) << std::endl;
//	//
//	p = new unsigned char[*i];
//	//
//	printf("p = %*p\n", &p);
//	system("pause");
//}


int main()
{

	//const char* ch = "01 05 00 00 00 01 00 01 00 0a 30 03 00 00 01";
	//printf("len:%d:",sizeof(ch));

	string mecaDataRspStr = "12 34 56 78 90 12 34 56 78 90 12 34 56 78 90";
	unsigned short totalMecaLen = mecaDataRspStr.length(), maxLenToPrint = 10;
	auto itr = mecaDataRspStr.begin();
	unsigned short pos = 0;
	while (itr < mecaDataRspStr.end())
	{
		cout << typeid(itr).name() << endl;
		string data = mecaDataRspStr.substr(pos, maxLenToPrint);
		unsigned short len = (totalMecaLen  > maxLenToPrint) ? maxLenToPrint : totalMecaLen;
		printf("data:%s\n", data.c_str());
		if (totalMecaLen < maxLenToPrint)
			break;
		totalMecaLen = totalMecaLen - maxLenToPrint;
		itr += maxLenToPrint;
		pos += maxLenToPrint;
	}

	return 0;
}