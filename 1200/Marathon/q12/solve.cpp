#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

void display(vector<long long> &v)
{
	for (auto i : v)
		cout << i << " ";
}

void twoset(long long n)
{
	long long sum = n * (n + 1) / 2;
	vector<long long> a, b;
	if (sum % 2 == 1)
	{
		cout << "NO" << endl;
		return;
	}
	else
	{
		cout << "YES ";
		long long ans = sum / 2;
		for (long long i = n; i >= 1; i--)
		{
			if (i <= ans)
			{
				a.push_back(i);
				ans -= i;
			}
			else
			{
				b.push_back(i);
			}
		}
	}
	cout << a.size() << " ";
	display(a);
	cout << b.size() << " ";
	display(b);
}
int main()
{
	long long n;
	cin >> n;
	twoset(n);
}