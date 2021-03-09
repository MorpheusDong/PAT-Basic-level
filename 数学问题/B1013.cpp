#include <iostream>

using namespace std;

const int maxn = 1000001;

int primeNum[maxn] = {0};
int pNum = 0;
bool p[maxn] = {0};

void findPrime(int n)
{
    for (int i = 2; i < maxn; ++i)
    {
        if (p[i] == false)
        {
            primeNum[pNum++] = i;
            if (pNum >= n)
                break;
            for (int j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    }
}

int main()
{
    int m, n;
    int count = 0;
    cin >> m >> n;
    findPrime(n);
    for (int i = m; i <= n; ++i)
    {
        cout << primeNum[i - 1];
        ++count;
        if (count % 10 != 0 && i < n)
            cout << " ";
        else
            cout << "\n";
    }
}

