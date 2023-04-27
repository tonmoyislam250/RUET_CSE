#include <iostream>
using namespace std;

int main()
{
	int c1 = 0;
	while (c1 != 3)
	{
		int balls = 20;
		cout << "Which player you want to play?\n1. player 1\n2. player 2\n3. Exit" << endl;
		cin >> c1;
		if (c1 == 1)
		{
			int i = 0;
			while (i >= 0)
			{
				int take = 20;
				if (i == 0)
					cout << "You are the first player" << endl;
				while (take > 4 || take < 1)
				{
					cout << "\nHow many balls you want to take? (1-4) = ";
					cin >> take;
					if (take > 4 || take < 1)
						cout << "Invalid Balls taken" << endl;
				}
				balls = balls - take;
				cout << "you have taken " << take << " balls remains : " << balls << endl;
				if (balls == 0)
				{
					cout << "You have won" << endl;
					break;
				}
				balls = balls - (5 - take);
				cout << "2nd Player (computer) have taken " << 5 - take << " balls remains : " << balls << endl;
				if (balls == 0)
				{
					cout << "Computer have won" << endl;
					break;
				}
				i = i + 1;
			}
		}
		else if (c1 == 2)
		{
			int i = 0;
			while (i >= 0)
			{
				int take;
				if (i == 0)
					cout << "Computer is the first player" << endl;
				if (balls % 5 == 0)
					take = rand() % 3 + 1;
				else
					take = balls - (5 * (balls / 5));

				balls = balls - take;
				cout << "Computer have taken " << take << " balls remains : " << balls << endl;
				if (balls == 0)
				{
					cout << "Computer have won" << endl;
					break;
				}
				int take2 = 20;
				while (take2 > 4|| take2 < 1)
				{
					cout << "\nHow many balls you want to take? (1-4) = ";
					cin >> take2;
					if (take2 > 4|| take2 < 1)
						cout << "Invalid Balls taken" << endl;
				}
				balls = balls - take2;
				cout << "you have taken " << take << " balls remains : " << balls << endl;
				if (balls == 0)
				{
					cout << "You have won" << endl;
					break;
				}
				i = i + 1;
			}
		}
	}
}