#include <iostream>

using namespace std;

int recur(int n)
{
	cout << "recur(" << n << ")" << endl;
	if (n == 1) return 1;
	return n + recur(n - 1);
}

int fsum(int n)
{
	cout << "fsum(" << n << ")" << endl;
	if (n == 1) return 1;
	if (n % 2 == 1) return fsum(n - 1) + n;
	return 2 * fsum(n / 2) + (n / 2)*(n / 2);
}

int main(void)
{
	return 0;
}