#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
	string name;
	string id;
	int score;
};

bool cmp(student x, student y)
{
	if (x.score < y.score)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	student* stu = new student[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> stu[i].name;
		cin >> stu[i].id;
		cin >> stu[i].score;
	}
	sort(stu, stu + n,cmp);    //从低到高排序
	cout << stu[n - 1].name << " " << stu[n - 1].id;    //成绩最高
	cout << endl;
	cout << stu[0].name << " " << stu[0].id;    //成绩最低

	delete[]stu;
	return 0;
}