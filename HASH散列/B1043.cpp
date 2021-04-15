#include <iostream>
#include <string>

using namespace std;

//hash表记录每个字符的数量，与下面dict一一对应
int hashTable[6] = { 0 };
char dict[6] = { 'P','A','T','e','s','t' };    //特定字符

int main()
{
	string s;
	int sum = 0;    //总共要输出的字符数量

	cin >> s;
	int len = s.length();

	//遍历字符串获取特定字符的数量
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < 6; ++j)    //查询是否是特定字符
		{
			if (s[i] == dict[j])
			{
				hashTable[j]++;    //对应数量+1
				sum++;
			}
		}
	}

	//输出所有特定字符
	while (sum > 0)
	{
		for (int i = 0; i < 6; ++i)
		{
			if (hashTable[i] > 0)
			{
				cout << dict[i];
				hashTable[i]--;
				sum--;
			}
		}
	}

}