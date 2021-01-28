#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int c1, c2;
	cin >> c1 >> c2;
	int c = c2 - c1;
	if (c % 100 >= 50)
		c = c / 100 + 1;
	else
		c = c / 100;
	cout << setw(2) << setfill('0') << c / 3600 << ":";    //hour
	cout << setw(2) << setfill('0') << c % 3600 / 60 << ":";    //minute
	cout << setw(2) << setfill('0') << c % 60;    //second

	return 0;
}