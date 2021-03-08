#include <iostream>
using namespace std;

#define MAXN    100000

int main()
{
    int n;
    int no, score;
    int schools[MAXN] = {0};
    cin >> n;
    for (int i = 0; i < n;++i)
    {
        cin >> no >> score;
        schools[no] += score;
    }
    int max_no = 1, max_score = 0;
    for (int i = 1; i <= n;++i)
    {
        if (schools[i] >= schools[max_no])
        {
            max_score = schools[i];
            max_no = i;
        }
    }
    cout << max_no << " " << max_score;
}
