#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main() {

	int totalIntger, number, totalQuery, queryNumber;

	vector<int> vectorNumber;
	vectorNumber.reserve(10);

	cin >> totalIntger;
	for (int i = 0; i < totalIntger; ++i)
	{
		cin >> number;
		vectorNumber.push_back(number);
	}

	cin >> totalQuery;

	for (int i = 0; i < totalQuery; ++i)
	{
		cin >> queryNumber;
		auto low = lower_bound(vectorNumber.begin(), vectorNumber.end(), queryNumber);
		if (vectorNumber[low - vectorNumber.begin()] == queryNumber)
			cout << "Yes " << (low - vectorNumber.begin() + 1) << endl;
		else
			cout << "No " << (low - vectorNumber.begin() + 1) << endl;

		//auto itr = std::find(vectorNumber.begin(), vectorNumber.end(), queryNumber);
		//if (itr != vectorNumber.end())
		//	std::cout << "Yes " << itr - vectorNumber.begin() + 1 << std::endl;
		//else
		//{
		//	auto last = vectorNumber.rbegin();
		//	if (queryNumber > *last)
		//		continue;
		//	int num = queryNumber + 1;
		//	bool found = false;
		//	while (true)
		//	{
		//		auto itr = find(vectorNumber.begin(), vectorNumber.end(), num);
		//		if (itr != vectorNumber.end())
		//		{
		//			std::cout << "No " << itr - vectorNumber.begin() + 1 << std::endl;
		//			break;
		//		}
		//		++num;
		//	}
		//}
	}
	string name = "";
	std::cin >> name;
	std::map<string, int> marks;
	marks.insert(pair<char *, int>(name, 100));
	return 0;
}