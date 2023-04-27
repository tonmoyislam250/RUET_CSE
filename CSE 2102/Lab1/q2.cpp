#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	bool u[n], w = true;
	for (int i = 0; i < n; i++)
	{
		if (w != false)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i] + b[j] > 0)
				{
					u[i] = true;
					break;
				}
				else
				{
					//cout << "False for y  " << a[i] << " " << b[j] << endl;
					w = false;
					u[i] = false;
				}
			}
		}
		//cout << u[i] << endl;
	}
	if (w)
		cout << "The Statement is True" << endl;
	else
		cout << "The Statement is False" << endl;
}