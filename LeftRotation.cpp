#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> split_string(string);



int main()
{
	string nd_temp;
	getline(cin, nd_temp);

	vector<string> nd = split_string(nd_temp);

	int n = stoi(nd[0]);

	int d = stoi(nd[1]);

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	vector<int> a(n);

	int  it = 0, a_item = 0, num = 0;

	if (n > d)
		it = d;
	else
		it = (d % n); 

	for (int i = it; i < n; ++i)
	{
		a_item = stoi(a_temp[i]);
		if (num < n)
			a[num] = a_item;
		++num;
	}
	for (int i = 0; i < it; ++i)
	{
		a_item = stoi(a_temp[i]);
		if (num < n)
			a[num] = a_item;
		++num;
	}

	for (auto itr : a)
		std::cout << itr << "\t";
	std::cout << std::endl;

	/*for (int i = 0; i < n; i++) {
		int a_item = stoi(a_temp[i]);

		a[i] = a_item;
	}*/

	system("pause");
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y && x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
