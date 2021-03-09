#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 10000    //给个足够大的空间

bool covered[MAXN] = {false};
int a[MAXN];    //存所有读取的数

bool cmp(int a, int b) { return a > b; }

void check(int x, bool c[])
{
    while (x != 1)
    {
        if (x % 2 != 0)
            x = 3 * x + 1;
        x = x / 2;
        if(c[x] == true)    //遇到覆盖的数，下面的序列都已经覆盖
            break;
        c[x] = true;
    }
}

int main()
{
    int n;
    int num;
    int flag = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        check(num, covered);
        a[i] = num;
    }
    sort(a, a+n, cmp);
    for (int i = 0; i < n; ++i)
    {
       if(covered[a[i]] == false)
       {
           if(flag == 1)
               cout << " ";
           cout << a[i];
           flag = 1;
       }
    }

}
