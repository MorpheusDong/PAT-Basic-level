#include<iostream>
#include<string>

#define charToNum(x)    (x-48)
#define enlChar         (-38)
#define maxsize         (10)    

using namespace std;

string numZh[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

int main()
{
	int sum = 0;
	int n;
	int res[maxsize], top = -1;
	n = charToNum(cin.get());
	while (n != enlChar)    //逐个读取直到换行符
	{
		sum += n;
		n = charToNum(cin.get());
	}
	while (sum != 0)    //不断取结果的个位入栈
	{
		res[++top] = sum % 10;
		sum /= 10;
	}
	while (top != -1)    //根据每一位输出对应字符
	{
		cout << numZh[res[top]];
		--top;
		if (top >= 0)
			cout << " ";
	}
	return 0;
}