#include <iostream>
using namespace std;

int main()
{
	int count[10];    //count[x]=数字x的数量
	for (int i = 0; i < 10; ++i)
		cin >> count[i];
	for (int i = 1; i < 10; ++i)    //找不为0的最小的数
	{
		if (count[i] > 0)    //只有有一个就输出，退出循环
		{
			cout << i;
			--count[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i)    //剩余的数字，从小到大，有几个就输出几个
	{
		for (int j = 0; j < count[i]; ++j)
			cout << i;
	}

	return 0;
}