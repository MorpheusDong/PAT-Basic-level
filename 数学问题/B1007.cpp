#include <iostream>
using namespace std;

#define MAXN    100000
int prime[MAXN];        //质数表
bool p[MAXN] = {false}; //判断是否筛选
int pNum = 0;           //指针

//找所有不超过正整数N的素数
void find_prime(int n)
{
    for (int i = 2; i <= n;++i) //注意这里的等号
    {
        if(p[i] == false)
        {
            prime[pNum++] = i;
            for (int j = i+i; j < n;j+=i)
                p[j] = true;
        }
    }
}

int main()
{
    int N;
    int count = 0;
    cin >> N;
    find_prime(N);
    for (int i = 1; i < pNum;++i)
    {
        if(prime[i] - prime[i-1] == 2) //相邻素数差为2，计数+1
            ++count;
    }
    cout << count;
}
