#include <iostream>
using namespace std;

int main()
{
	char s;
	int c, r;
	cin >> c;
	cin >> s;
	if (c % 2 == 0)
		r = c / 2;
	else
		r = c / 2 + 1;
	for (int i = 1; i <= r; ++i)
	{
		if (i == 1)
		{
			for (int j = 0; j < c; ++j)
				cout << s;
		}
		else if (i > 1 && i < r)
		{
			cout << s;
			for (int j = 0; j < c - 2; ++j)
				cout << " ";
			cout << s;
		}
		else
		{
			for (int j = 0; j < c; ++j)
				cout << s;
		}
		cout << endl;
	}

}