#include <iostream>
using namespace std;

int main()
{
	int n;
	int ge = 0, shi = 0, bai = 0;
	cin >> n;
	ge = n % 10;
	shi = n / 10 % 10;
	bai = n / 100;
	for (int i = 0; i < bai; ++i)
		cout << "B";
	for (int i = 0; i < shi; ++i)
		cout << "S";
	for (int i = 1; i <= ge; ++i)
		cout << i;
	return 0;
}