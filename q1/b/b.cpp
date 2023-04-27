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
void intersect(int a[], int b[], int s, int s2)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			if (a[i] == b[j])
			{
				last[k] = a[i];
				k++;
				break;
			}
		}
	}
}

void removedup(int a[], int s)
{
	int i, j;
	for (i = 0; i < s; i++)
	{
		for (j = 0; j < r; j++)
		{
			if (last[i] == ans[j])
				break;
		}

		if (j == r)
		{
			ans[r] = last[i];
			r++;
		}
	}
}

int main()
{
	int n, m;
	cout << "input size" << endl;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	intersect(a, b, n, m);
	removedup(ans, n + m);
	print(ans, n + m);
}