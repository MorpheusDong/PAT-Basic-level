#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hashTable[100] = { 0 };

int main()
{
	int n, m;
	int score;
	int flag = 0;
	vector<int> ans;
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> score;
		hashTable[score]++;
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> score;
		ans.push_back(hashTable[score]);
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		if (flag == 1)
			cout << " ";
		cout << ans[i];
		flag = 1;
	}
}