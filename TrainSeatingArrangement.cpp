//#include <iostream>
//
//void oppsiteSeatAndBirth(const int &num) {
//	
//	if (num < 0 || num > 108)
//	{
//		std::cout << "You have entered the wrong seat number. \nPlease try again." << std::endl;
//		return;
//	}
//
//	int diff = (num % 12);
//	switch (diff)
//	{
//		// For Window seat.
//		case 0:
//		case 1:
//		case 6:
//		case 7:
//		{
//			std::cout << "Your alloted seat " << num << " is a window." << std::endl;
//			std::cout << "The opposite seat number is ";
//			if (diff == 0 || diff == 1)
//				(diff == 0) ? std::cout << num - 11 : std::cout << num + 11;
//			else
//				(diff == 6) ? std::cout << num + 1 : std::cout << num - 1;
//		}
//		break;
//		// For Middle seat.
//		case 2:
//		case 11:
//		case 5:
//		case 8:
//		{
//			std::cout << "Your alloted seat " << num << " is a middle." << std::endl;
//			std::cout << "The opposite seat number is ";
//			if (diff == 2 || diff == 11)
//				 (diff == 2) ? std::cout << num + 9 : std::cout << num - 9;
//			else
//				(diff == 5) ? std::cout << num + 3 : std::cout << num - 3;
//		}
//		break;
//		// For Aisle seat.
//		case 3:
//		case 10:
//		case 4:
//		case 9:
//		{
//			std::cout << "Your alloted seat " << num << " is a aisle." << std::endl;
//			std::cout << "The opposite seat number is ";
//			if (diff == 3 || diff == 10)
//				(diff == 3) ? std::cout << num + 7 : std::cout << num - 7;
//			else
//				(diff == 4) ? std::cout << num + 5 : std::cout << num - 5;
//		}
//		break;
//		default:
//			break;
//	}
//	std::cout << ".\nHappy Journey!\n\n";
//}
//
//int main()
//{
//	oppsiteSeatAndBirth(26);
//	oppsiteSeatAndBirth(33);
//	oppsiteSeatAndBirth(31);
//	oppsiteSeatAndBirth(108);
//	oppsiteSeatAndBirth(109);
//
//	system("pause");
//}

//***************************************************
//
//				Optimized method
//
// **************************************************

#include <iostream>
#include <vector>

using namespace std;

const int ROW_SZ = 18;
const int COL_SZ = 6;


vector<string> s({ "WS", "MS", "AS", "AS", "MS", "WS" });

int main()
{
	int a[ROW_SZ][COL_SZ] = { 0 };
	int seat;
	unsigned int testcase;
	cin >> testcase;


	for (int i = 0; i < ROW_SZ; i++)
	{
		for (int j = 0; j < COL_SZ; j++)
		{
			if (i % 2 == 0)
				a[i][j] = i*COL_SZ + j + 1;
			else
				a[i][j] = i*COL_SZ - j + COL_SZ;
		}
	}

	cout << endl;
	while (testcase)
	{


		cin >> seat;
		cout << endl;
		if (seat > 108 || seat < 1)
			return 0;

		int ri = 0, ci = 0;

		ri = (seat - 1) / COL_SZ;
		if ((ri & 0x01) == 0)
		{
			ci = (seat - 1) % COL_SZ;
			ri += 1;
		}
		else
		{
			ci = (seat - 1) % COL_SZ;
			ci = COL_SZ - ci - 1;
			ri -= 1;
		}
		std::cout << a[ri][ci] << " " << s[ci].c_str();
		cout << endl;
		testcase--;
	}
	system("pause");
	return 0;
}
