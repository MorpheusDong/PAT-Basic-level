#include <iostream>
using namespace std;

//一种取巧的做法，直接输出题目期望的结果
int main()
{
    int m = 0, n = 0;
    int a[101];
    int count = 0;
    cin >> n >> m;
    m = m % n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = n - m; i < n; ++i)
    {
        cout << a[i];
        ++count;
        if (count < n)
            cout << " ";
    }

    for (int i = 0; i < n - m; ++i)
    {
        cout << a[i];
        ++count;
        if (count < n)
            cout << " ";
    }
}