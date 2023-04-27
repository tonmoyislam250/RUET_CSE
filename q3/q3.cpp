#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cout << "input set size" << endl;
	cin >> n;
	int a[n];
	cout << "enter set values" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int p = pow(2, n);
	cout<<"{ ";
	for (int j = 0; j < p; j++)
	{
		int jj;
		cout << "{ ";
		for (jj = 0; jj < n; jj++)
		{
			if (j & 1 << jj)
				cout << a[jj] << " ";
		}
		cout << "}, ";
	}
	cout<<" }";
}