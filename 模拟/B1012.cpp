#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int num;
    int A[6] = {0};
    int countA2 = 0;
    int countA4 = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        if (num % 5 == 0 && num % 2 == 0)    //余数，奇偶判断
            A[1] += num;
        else if (num % 5 == 1)
        {
            if (countA2 % 2 == 0)    //交错的控制
                A[2] += num;
            else
                A[2] -= num;
            ++countA2;
        }
        else if (num % 5 == 2)    //余数
            ++A[3];
        else if (num % 5 == 3)    //余数
        {
            A[4] += num;
            ++countA4;    //计数
        }
        else if (num % 5 == 4 && num >= A[5])    //求最大值
            A[5] = num;
        else
        {
            //do nothing
        }
    }

    for (int i = 1; i <= 3; ++i)
    {
        if (A[i] != 0)
            cout << A[i] << " ";
        else
            cout << "N ";
    }
    if (countA4 != 0)
        cout << fixed << setprecision(1) <<  A[4]*1.0 / countA4 << " ";
    else
        cout << "N ";
    cout.unsetf(ios::fixed);
    if (A[5] != 0)
        cout << A[5];
    else
        cout << "N";
}
