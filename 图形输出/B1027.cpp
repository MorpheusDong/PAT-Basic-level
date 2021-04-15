#include <iostream>
using namespace std;

//打印x个空格
void space(int x)
{
	for (int i = 0; i < x; ++i)
		cout << " ";
}

//打印x个符号
void symbol(int x,char c)
{
	for (int i = 0; i < x; ++i)
		cout << c;
}

//思路：
//从中心往外观察符号的个数，是个奇数数列，1,3,5……
//符号个数的规律为1+2*3,1+2*3+2*5,1+2*3+2*5+2*7……
//所以可以递增一个奇数，统计能使用的符号数量，然后根据规律输出字符即可

int main()
{
	char c;
	int n;    //输入的数量
	cin >> n >> c;

	int i = 1;    //i是个递增的奇数，同时也是首行符号的个数
	int sum = 1;    //sum统计能使用的符号数量
	while (sum <= n)
	{
		i += 2;
		sum += 2 * i;
	}

	//当sum大于n时，要回退一下
	sum -= 2 * i;
	i -= 2;

	//逐行输出
	for (int line = 0,j = i; line < i; ++line)    //j是每行要输出的符号个数
	{
		if (line < i / 2)
		{
			space((i - j) / 2);
			symbol(j,c);
			j -= 2;
		}
		else
		{
			space((i - j) / 2);
			symbol(j, c);
			j += 2;
		}
		cout << "\n";
	}

	cout << n - sum;
}

