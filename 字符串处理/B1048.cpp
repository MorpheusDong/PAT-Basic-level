#include <iostream>
#include <string>

#define charToInt(x)    ((int)x-48)

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    int aLen = A.length();
    int bLen = B.length();
    int count = 1;    //位指针，开始指向个位，个位是第1位
    char c[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };    //密文

    if (aLen > bLen)    //A比B长，需要在B前面补0
    {
        for (int i = 0; i < aLen - bLen; ++i)
            B = '0' + B;
    }
    bLen = B.length();    //重新获取B的长度

    //上面的操作会在A>=B时把A和B对齐，但B更长时不需要
    for (int i = aLen - 1,j = bLen-1; i >= 0; --i,--j,++count)
    {
        int num;    //对应位加密的结果
        if (count % 2 != 0)    //当前处理的是奇数位
            num = (charToInt(A[i]) + charToInt(B[j])) % 13;
        else    //当前处理的是偶数位
        {
            num = charToInt(B[j]) - charToInt(A[i]);
            if (num < 0)
                num += 10;
        }
        B[j] = c[num];    //根据结果转换为密文
    }

    cout << B;
}

/*--------总结--------*/
//1.注意题目里的隐含条件。当A更长时，要把B加密成和A一样长。
//2.位数较多的整数用字符串处理，注意每一位的操作。
/*--------总结--------*/
