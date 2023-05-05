#include <iostream>
#include <cmath>
using namespace std;
long long c = 0;
long long pre = 0;
long long s = 0;
void varsum(int a, int siz, int arr[])
{
	if (a <= 0)
	{
		cout << "The sum is " << pre << endl;
		return;
	}
	else
	{
		int L, U;
		cin >> L >> U;
		int pin = (U - L) + 1;
		for (int j = L; j <= U; j++)
			s += (arr[c] * j);
		for (int kk = c + 1; kk < siz; kk++)
			arr[kk] *= pin;
		pre = pre * pin + s;
		s = 0;
	}
	a--;
	c++;
	varsum(a, siz, arr);
}
int main()
{
	int var;
	cout << "Enter How many Sum signs : ";
	cin >> var;
	int val[var];
	cout << "Order the Sum signs and variables from left to right" << endl;
	cout << "The " << var << " Coefficients Left to right: ";
	for (int i = 0; i < var; i++)
		cin >> val[i];
	cout << "Enter Low and Up from left to Right : ";
	varsum(var, var, val);
}