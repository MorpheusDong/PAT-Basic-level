#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[100010];

int main()
{
	/*根据题设，把整个序列排好序以后，满足条件的序列是其中的子序列*/
	/*所以应想到双指针的做法，在左右端各设一个指针来求最大长度。时间复杂度为O(n)*/
	int n, p;

	//读取数据
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	//递增排序
	sort(a, a + n);

	int count = 1;
	for (int i = 0, j = 0; i < n&&j < n; ++i)    //每次j移动完以后，i右移一位，寻找新的子序列
	{
		while (j < n&&a[j] <= (long long)p*a[i])    //持续移动j，直到当前序列恰好不满足条件
		{
			++j;
		}
		count = (j - i > count) ? j - i : count;    //更新最大长度
	}

	cout << count;

	/* 第二种做法，用二分查找找到j的位置，时间复杂度为O(logn)

	vector<int> V;
	int n, p;
	int temp;

	//读取数据
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		V.push_back(temp);
	}

	//从小到大排序
	sort(V.begin(), V.end(), less<int>());

	int max = 1;    //序列的最大长度
	for (int i = 0; i < n; ++i)
	{
		//从剩余序列中，找第一个大于p倍左端点（p*V[i]）的数的位置j，j-i就是满足条件的序列的长度
		int j = upper_bound(V.begin() + i + 1, V.end(), (long long)V[i] * p) - V.begin();    //注意用longlong避免溢出
		max = (j - i > max )? j - i : max;    //更新最大
	}
	cout << max;

	*/
}