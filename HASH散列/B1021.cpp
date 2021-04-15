#include <iostream>

using namespace std;

int change(char c)
{
	return c - '0';
}

int hashTable[10] = { 0 };

int main()
{
	char c;

	while (cin.get(c) && c != '\n')
	{
		int n = change(c);
		hashTable[n]++;
	}

	int flag = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (hashTable[i] > 0)
		{
			if (flag == 1) cout << "\n";
			cout << i << ":" << hashTable[i];
			flag = 1;
		}
	}
}

