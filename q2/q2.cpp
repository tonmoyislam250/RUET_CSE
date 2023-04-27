#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, m, cnt = 0;
	int prev;
	cout << "Domain and range size : ";
	cin >> n >> m;
	int a[n], b[m];
	cout << "Domains : ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Ranges : ";
	for (int j = 0; j < m; j++)
		cin >> b[j];
	int y, x = 0;
	int choice = 0, choice2;
	cout << "Enter your choice >\n1. (x^2)+1\n2. (x^3)+(x^2)-x-1\n3. (x^5)+(x^2)-x\n";
	while (choice == 0)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			choice2 = 1;
			break;
		case 2:
			choice2 = 2;
			break;
		case 3:
			choice2 = 3;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		x = a[i];
		if (choice2 == 1)
			y = pow(x, 2) + 1;
		else if (choice2 == 2)
			y = pow(x, 3) + pow(x, 2) - x - 1;
		else if (choice2 == 3)
			y = pow(x, 5) + pow(x, 2) - x;
		for (int j = 0; j < m; j++)
		{
			//cout << "y value =" << y << endl;
			if (y == b[j] && prev != y)
			{
				cnt++;
				prev = y;
				break;
			}
		}
	}
	if (cnt == n)
		cout << "Function is one-one" << endl;
	else
		cout << "Function is not one-one" << endl;
}