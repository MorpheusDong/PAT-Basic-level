#include <iostream>
using namespace std;

#define MAXN    1001

int main()
{
    int num[MAXN]; //被除整数
    char n;        //读取到的每一位数字
    int div;       //被除数
    int i;         //位指针

    //读取被除整数
    for (i = 0; (n = cin.get()) != ' '; ++i) //循环结束时i为整数长度
        num[i] = (int)(n - '0');

    //读取除数
    cin >> div;

    if (i == 1) //只有一位的特殊情况
        cout << num[0] / div << " " << num[0] % div;
    else //至少两位的情况，模拟手动除法
    {
        int t = num[0];
        int j = 1;        //j提供借位
        if (t / div == 0) //先让头部除，不够借一位
        {
            t = num[0] * 10 + num[1];
            j = 2;
        }
        cout << t / div;   //输出商
        for (; j < i; ++j) //处理后面几位
        {
            t = (t % div) * 10 + num[j]; //除完取余数，借一位再继续除。这一步是手动除法的关键。
            cout << t / div;             //输出商
        }
        cout << " " << t % div; //输出余数
    }
}
