#include <iostream>   
#include <string>
using namespace std;

int main()
{
	string s;
	char r[80][80] = {};    //存放单词的二维数组初始化为空
	getline(cin, s);    //整行字符串读入s
	unsigned int i = 0,j = 0,k = 0;

	for (i = 0; i < s.length(); ++i)
	{
		if (s[i] != ' ')
		{
			r[j][k++] = s[i];    //读入第j个单词的所有字符
		}
		else    //空格标志一个单词结束
		{
			++j;    //准备读下一个单词
			k = 0;    //重置单词字符的指针
		}
	}

	for (int i = j; i >= 0; --i)    //倒序输出单词序列
	{
		cout << r[i];
		if (i > 0)
			cout << " ";    //控制空格
	}
}