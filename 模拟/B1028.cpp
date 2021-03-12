#include <iostream>
#include <string>
using namespace std;

#define RLEFT    (18140906)
#define RRIGHT   (20140906)

struct residents_st
{
    string name;
    long long birthInt;
};

/* 注：思路是对的，但不知为何测试点0通不过，我怎么都查不出来哪里不对 */
/* 相同思路在C语言下实现可以通过 */
int main()
{
    int n; //输入个数
    int count = 0; //有效日期个数
    int y, m, d; //年月日
    int max = 0, min = 0; //指针

    cin >> n;
    residents_st* residents = new residents_st[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> residents[i].name; 
        string temp;
        getline(cin, temp, '/'); 
        y = stoi(temp);
        getline(cin, temp, '/');
        m = stoi(temp);
        getline(cin, temp);
        d = stoi(temp);
        residents[i].birthInt = y * 10000 + m * 100 + d;    //生日组成整数比较
        if (residents[i].birthInt >= RLEFT && residents[i].birthInt <= RRIGHT) //有效日期判断
        {
            ++count;
            if (residents[i].birthInt <= residents[max].birthInt)
                max = i;
            if (residents[i].birthInt >= residents[min].birthInt)
                min = i;
        }
    }

    if (count != 0)
        cout << count << " " << residents[max].name << " " << residents[min].name;
    else
        cout << "0";

    delete[] residents;
}
