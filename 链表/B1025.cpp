#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int first, k, n;
	int data[100010], next[100010];    //分配两个数组存数据和游标
	vector<int> list;    //在VS环境下继续分配list[100010]会导致栈溢出

	cin >> first >> n >> k;

	//读取所有节点信息
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		cin >> data[temp] >> next[temp];
	}

	//参考柳神的做法，list按顺序存放所有节点地址
	while(first != -1)
	{
		list.push_back(first);
		first = next[first];
	}

	//对地址反转
	vector<int>::iterator it = list.begin();
	for (int i = 0; i < n - n % k; i += k)
	{
		reverse(it + i, it + i + k);
	}

	//按照反转后的地址顺序去遍历输出即可
	for (int i = 0; i < n-1; ++i)
	{
		printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
	}

	//输出最后一个节点
	printf("%05d %d -1", list[n - 1], data[list[n - 1]]);
}

