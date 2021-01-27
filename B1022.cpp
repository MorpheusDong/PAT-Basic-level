#include <iostream>   
using namespace std;

int main()
{
	int a, b, d;
	int sum;
	int result[31];    //存放转换后的二进制数
	int n = 0;    //result的位指针
	cin >> a >> b >> d;
	sum = a + b;
	do
	{
		result[n++] = sum % d;    //取余数
		sum /= d;    //计算商
	} while (sum != 0);
	for (int i = n - 1; i >= 0; --i)
		cout << result[i];
}