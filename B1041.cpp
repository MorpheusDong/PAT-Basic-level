#include <iostream>
using namespace std;

#define MAXN    1000

struct studentInfo
{
    string id;
    int examSeat;
} students[MAXN];

int main()
{
    int n;
    int m;
    int pc;
    string idTemp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> idTemp;
        cin >> pc;
        students[pc].id = idTemp;
        cin >> students[pc].examSeat;
    }
    cin >> m;
    int num;
    for (int i = 0; i < m; ++i)
    {
        cin >> num;
        cout << students[num].id << " " << students[num].examSeat;
        if (i < m - 1)
            cout << "\n";
    }
}
