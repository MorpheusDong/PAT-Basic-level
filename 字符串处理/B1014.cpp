#include <iostream>
#include <map>
#include <iomanip>

#define ltoT(x)    (x-'A'+10)

using namespace std;

int main()
{
    map<char, string> dayM;    //字母到星期的映射
    dayM.insert(make_pair('A', "MON"));
    dayM.insert(make_pair('B', "TUE"));
    dayM.insert(make_pair('C', "WED"));
    dayM.insert(make_pair('D', "THU"));
    dayM.insert(make_pair('E', "FRI"));
    dayM.insert(make_pair('F', "SAT"));
    dayM.insert(make_pair('G', "SUN"));
    string A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    int lenA1 = A1.length(), lenA2 = A2.length();
    int lenB1 = B1.length(), lenB2 = B2.length();
    int i = 0;

    //寻找星期，即第一对相同的A~G的字母
    for (i = 0; i < lenA1 && i < lenA2; ++i)
    {
        if (A1[i] == A2[i] && A1[i] >= 'A' && A1[i] <= 'G')
        {
            cout << dayM[A1[i]] << " ";
            break;    //找到就退出
        }
    }

    //寻找小时，即后面字符串中第一对相同的数字或A~N的字母
    for(++i; i < lenA1 && i < lenA2; ++i)
    {
        if (A1[i] == A2[i])
        {
            if (A1[i] >= '0' && A1[i] <= '9')
            {
                cout << setw(2) << setfill('0') << A1[i] << ":";    //注意补0
                break;
            }
            else if (A1[i] >= 'A' && A1[i] <= 'N')
            {
                cout << ltoT(A1[i]) << ":";    //字母偏移到时间
                break;
            }
        }
    }

    //寻找分钟，即第一对相同字母的位置
    for (int i = 0; i < lenB1 && i < lenB2; ++i)
    {
        if (B1[i] == B2[i] && isalpha(B1[i]) && isalpha(B2[i]))
        {
            cout << setw(2) << setfill('0') << i;    //注意补0
            break;    //找到就退出
        }
    } 
}


/*--------总结--------*/
//1.此题关键在于理解题意，且细节很多
//2.注意星期判断范围是A~G，星期结束后的相同字符才是小时，每次找到后就退出循环
//3.注意字母和数字的转换，有很多种写法，可以用和字符作差再偏移，也可以直接转整数相减
//4.注意格式化输出补0
/*--------总结--------*/
