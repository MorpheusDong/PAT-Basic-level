#include <iostream>
#include <string>
#include <vector>

#define charToInt(x)    ((int)x-48)

using namespace std;

int main()
{
    int n;    
    int Z;    
    string id;
    int count = 0;    //合法id计数
    vector<string> id_failed;    //无效id
    char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };    //校验码
    int w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };    //各位权重

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> id;
        int j = 0, sum = 0;
        for (j = 0; j < 17; ++j)    //检查前17位
        {
            if (id[j] >= '0' && id[j] <= '9')    //每位都为数字
            {
                sum += charToInt(id[j]) * w[j];    //加权求和
            }
            else
                break;    //有一位不是数字就跳出
        }
        if (j < 17)    //前17位内含非数字
        {
            id_failed.push_back(id);
        }
        else    //前17位都是数字
        {
            Z = sum % 11;
            if (id[17] == M[Z])    //验证校验位
                ++count;    //有效id+1
            else
                id_failed.push_back(id);    //校验位无效
        }
    }

    if (count == n)    //全部通过
        cout << "All passed";
    else    //顺序输出所有无效id
    {
        unsigned int k = 0;
        for (k = 0; k < id_failed.size(); ++k)
        {
            cout << id_failed[k];
            if (k < id_failed.size() - 1)    //换行控制
                cout << "\n";
        }
    }
}


/*--------总结--------*/
//1.遍历字符串，对每一位做检查（本题为是否为数字，加权求和）
//2.考虑每一位都有相应操作时，如何存储数组（本题为校验码，权重，有的是hash表）
//3.使用vector来存储满足一定条件的数据，最后一起输出（本题为无效id）
/*--------总结--------*/
