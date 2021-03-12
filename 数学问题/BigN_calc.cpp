#include <iostream>
#include <string>
using namespace std;

struct bigN
{
    int d[1000] = { 0 };
    int len = 0;
};

//大整数加法
bigN add(bigN a, bigN b)
{
    bigN c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; ++i)    //以较长的为界限
    {
        int temp = a.d[i] + b.d[i] + carry;    //各位相加，再加进位
        c.d[c.len++] = temp % 10;    //个位作为结果
        carry = temp / 10;    //取十位作为进位
    }
    if (carry != 0)    //剩下的进位放在最前
        c.d[c.len++] = carry;
    return c;
}

//大整数减法
bigN sub(bigN a, bigN b)
{
    bigN c;
    for (int i = 0; i < a.len || i < b.len; ++i)    //以较长的为界限
    {
        if (a.d[i] < b.d[i])    //不够减
        {
            --a.d[i + 1];    //向高位借位
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];    //对应位相减
    }
    while (c.d[c.len - 1] == 0 && c.len - 1 >= 1)    //高位可能剩0，要把长度挪一下
        --c.len;
    return c;
}

//字符串转整数
bigN change(string str)
{
    bigN a;
    int len = str.length();
    for (int i = 0; i < len; ++i)
        a.d[a.len++] = str[len - 1 - i] - '0';    //逆序
    return a;
}

void pause()
{
    cout << "press any key to exit...";
    cin.get();
    cin.get();
}

//打印整数
void show(bigN a)
{
    for (int i = a.len - 1; i >= 0; --i)
        cout << a.d[i];
}

int main()
{
    string a, b;
    cin >> a >> b;
    bigN bigA = change(a);
    bigN bigB = change(b);
    //bigN c = add(bigA, bigB);
    bigN c = sub(bigA, bigB);
    show(c);

    //pause();
}
