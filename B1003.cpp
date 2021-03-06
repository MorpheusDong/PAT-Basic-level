#include <iostream>
using namespace std;

int main()
{
    int A_pre = 0, A_mid = 0, A_end = 0;
    int P = 0, T = 0;
    int n;
    cin >> n;
    string* str = new string[n];
    for (int i = 0; i < n; ++i)
        cin >> str[i];
    for (int i = 0; i < n; ++i,P = 0,T = 0, A_pre = 0, A_mid = 0, A_end = 0)
    {
        //每个字符串的处理
        for (int j = 0; j < str[i].size(); ++j)    
        {
            if (P == 0)
            {
                if (str[i][j] == 'A')
                    ++A_pre;
                else if (str[i][j] == 'P')
                    ++P;
                else
                    break;
            }
            else if (P == 1 && T == 0)
            {
                if (str[i][j] == 'A')
                    ++A_mid;
                else if (str[i][j] == 'T')
                    ++T;
                else
                    break;
            }
            else if (P == 1 && T == 1)
            {
                if (str[i][j] == 'A')
                    ++A_end;
                else
                    break;
            }
        }

        //输出结果
        if (P == 1 && T == 1 && A_mid > 0 && (A_pre * A_mid == A_end))
            cout << "YES";
        else
            cout << "NO";
        if (i < n - 1)
            cout << "\n";
    }

    delete[]str;
}

