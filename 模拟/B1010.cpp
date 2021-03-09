#include <iostream>
using namespace std;

int main()
{
    int a, b, flag = 0;   
    while(cin>>a>>b)    //输入结束就会返回false
    {
        if(b!=0)
        {
            if(flag == 1)
                cout << " ";    //2.后面再输出结果之前，先输出一个空格
            cout << a * b << " " << b - 1;
            flag = 1;    //1.只要有结果输出，flag就置为1
        }
    }
    if(flag == 0)    //零多项式
        cout << "0 0";
}
