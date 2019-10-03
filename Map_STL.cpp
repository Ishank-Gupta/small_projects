//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <set>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int numberOfQuery, query, marks = 0;
//	std::std::string name = "";
//	std::map<std::std::string, int> marksheet;
//	cin >> numberOfQuery;
//	for (int i = 0; i < numberOfQuery; ++i)
//	{
//		cin >> query;
//		cin >> name;
//		cin >> marks;
//		switch (query)
//		{
//		case 1:
//		{
//			auto itr = marksheet.find(name);
//			if (itr == marksheet.end())
//				marksheet.insert(pair<std::std::string, int>(name, marks));
//			else {
//				marks += itr.second;
//				itr.second = marks;
//			}
//		}
//		break;
//		case 2:
//			marksheet.erase(name);
//			break;
//		case 3:
//		{
//			auto itr = marksheet.find(name);
//			std::cout << itr.second << std::endl;
//		}
//		break;
//		default:
//			break;
//		}
//
//	}
//	return 0;
//}

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int Query;
	std::string name;
	int type, marks;

	map<std::string, int> marksheet;
	map<std::string, int>::iterator itr;

	cin >> Query;

	while (Query--) {
		cin >> type >> name;
		itr = marksheet.find(name);
		switch (type) {
		case 1:
			cin >> marks;
			if (itr != marksheet.end()) {
				marksheet[name] += marks;
			}
			else {
				marksheet.insert(make_pair(name, marks));
			}
			break;
		case 2:
			if (itr != marksheet.end()) {
				marksheet.erase(itr);
			}
			break;
		case 3:
			if (itr != marksheet.end()) {
				std::cout << itr.second << std::endl;
			}
			else {
				std::cout << 0 << std::endl;
			}
			break;
		}
	}

	return 0;
}