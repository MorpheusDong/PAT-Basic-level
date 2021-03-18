#include <iostream>
using namespace std;

//输出获胜次数最大的手势
void winMax(int a[],int n)
{
    int m = 0;
    for (int i = 0; i < n;++i)
    {
        if(a[i]>a[m])
            m = i;
        else if(a[i] == a[m]) //次数相同时，选择字母序较小的手势
        {
            m = (m == 0 && i == 1) ? m : i; //锤子(C)和剪刀(J)次数相同m不变，其它都变
        }
    }
    switch(m) //输出次数最大的手势
    {
        case 0:
            cout << "C";
            break;
        case 1:
            cout << "J";
            break;
        case 2:
            cout << "B";
            break;
    }
}

int main()
{
    int winA[3] = {0}; //甲每个手势获胜的次数
    int winB[3] = {0}; //乙每个手势获胜的次数
    int round = 0;     //回合数
    char A;            //甲出招
    char B;            //乙出招

    cin >> round;
    
    //根据两人出招分情况讨论
    for (int i = 0; i < round;++i)
    {
        cin >> A;
        cin >> B;
        
        if(A == 'C') //甲出锤子
        {
            if(B == 'J')
                ++winA[0];
            else if(B == 'B')
                ++winB[2];
        }
        else if(A == 'J') //甲出剪刀
        {
            if(B == 'B')
                ++winA[1];
            else if(B == 'C')
                ++winB[0];
        }
        else //甲出布
        {
            if(B == 'C') 
                ++winA[2];
            else if(B == 'J')
                ++winB[1];
        }
    }

    int win_A = winA[0] + winA[1] + winA[2];    //甲获胜次数
    int win_B = winB[0] + winB[1] + winB[2];    //乙获胜次数
    int even = round - win_A - win_B;           //平手次数
    cout << win_A << " " << even << " " << win_B << "\n";
    cout << win_B << " " << even << " " << win_A << "\n";
    winMax(winA, 3);cout << " ";winMax(winB, 3);    //输出甲乙获胜次数最高的手势
}
