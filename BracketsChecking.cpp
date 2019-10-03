#include <iostream>
#include <stack>

std::stack<char> s_brackets;

bool checkBrackets(std::string st)
{
	size_t len = st.length();
	bool fine = true;
	//
	for (int i = 0; i < len; ++i)
	{
		if (st[i] == '(' || st[i] == '{' || st[i] == '[')
			s_brackets.push(st[i]);
		else if (st[i] == ')' || st[i] == '}' || st[i] == ']')
		{
			if (s_brackets.size())
			{
				if ((st[i] == ')' &&  s_brackets.top() != '(') || (st[i] == '}' &&  s_brackets.top() != '{') || (st[i] == ']' &&  s_brackets.top() != '[')) {
					fine = false;
					break;
				}
				else
					s_brackets.pop();
			}
			else {
				fine = false;
				break;
			}
		}
	}
	if (fine && s_brackets.size())
		fine = false;

	return fine;
}

int main()
{

	std::string str = "{[[(())]]}";
	bool fine = checkBrackets(str);

	if (fine)
		std::cout << "In the string: \"" << str.c_str() << "\".\nThe brackets are paired and closed properly.\n";
	else
		std::cout << "In the string: \"" << str.c_str() << "\".\nThe brackets are not paired and closed properly.\n";

	system("pause");
}