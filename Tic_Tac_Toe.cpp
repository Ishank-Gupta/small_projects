#include <iostream>
#include <set>

using namespace std;

char place[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
set<int> num;
void board();
int checkwin();


int main()
{
	int player = 1, choice;
	int i = 1;
	for (int i = 1; i < 10; ++i)
		num.insert(i);
	do
	{
		board();
		player = (player % 2 != 0) ? 1 : 2;
		cout << "Player " << player << ", Enter a number: ";
		cin >> choice;
		if ((choice > 0 && choice < 10) && (place[choice] != 'X' && place[choice] != 'O'))
		{
			auto itr = num.find(choice);
			if(itr != num.end())
				num.erase(choice);
			(player == 1) ? place[choice] = 'X' : place[choice] = 'O';
		}
		else {
			cout << "Wrong choice.\n";
			player--;
		}
		i = checkwin();
		player++;
	} while (i == -1);
	board();
	if (i == 1)
		cout << "==>\a\tPlayer " << --player << " win \n";
	else
		cout << "==>\a\tGame draw\n";

	system("pause");
}

void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << place[1] << "  |  " << place[2] << "  |  " << place[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << place[4] << "  |  " << place[5] << "  |  " << place[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << place[7] << "  |  " << place[8] << "  |  " << place[9] << endl;
	cout << "     |     |     " << endl << endl;
}

int checkwin()
{
	if (num.empty())
		return 0;
	else if ((place[1] == place[2] && place[2] == place[3])
		  || (place[4] == place[5] && place[5] == place[6])
		  || (place[7] == place[8] && place[8] == place[9])
		  || (place[1] == place[4] && place[4] == place[7])
		  || (place[2] == place[5] && place[5] == place[8])
		  || (place[3] == place[6] && place[6] == place[9])
		  || (place[1] == place[5] && place[5] == place[9])
		  || (place[3] == place[5] && place[5] == place[7]))
		return 1;
	else
		return -1;
}
