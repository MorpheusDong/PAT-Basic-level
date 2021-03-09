#include <iostream>

using namespace std;

int main()
{
    int failA = 0, failB = 0;
    int A1, A2, B1, B2;
    int round = 0;
    cin >> round;
    for (int i = 0; i < round; ++i)
    {
        cin >> A1 >> A2 >> B1 >> B2;
        if ((A1 + B1 == A2) && (A1+B1 != B2))
        {
            ++failB;
        }
        else if ((A1 + B1 == B2) && (A1+B1 != A2))
        {
            ++failA;
        }
        else
        {
            //do nothing
        }
    }
    cout << failA << " " << failB;
}