#include <iostream>
using namespace std;
int last[1000], k = 0, r = 0;
int ans[1000];
void print(int a[], int s)
{
	for (int i = 0; i < s; i++)
	{
		if (a[i] != 0)
			cout << a[i] << " ";
	}
}
void difference(int a[], int b[], int s, int s2)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			if (a[i] == b[j])
			{
				a[i] = 0;
				break;
			}
		}
	}
}

int main()
{
	int n, m;
	cout << "input size" << endl;
	cin >> n >> m;
	int U[n], a[m];
	for (int i = 0; i < n; i++)
		cin >> U[i];
	for (int j = 0; j < m; j++)
		cin >> a[j];
	difference(U, a, n, m);
	print(U, n);
}