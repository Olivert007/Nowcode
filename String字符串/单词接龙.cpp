#include <iostream>
using namespace std;
bool hasFollow(int idx, char** arr, int* flag, int num)
{
	int i = 0;
	for (i = 0; i<num; i++)
	{
		if (flag[i] == 0 && arr[idx][strlen(arr[idx]) - 1] == arr[i][0])
		{
			flag[i] = 1;
			hasFollow(i, arr, flag, num);
		}
	}
	int sum = 0;
	for (i = 0; i<num; i++)
	{
		sum += flag[i];
	}
	if (sum == num)
		return true;
	else
		return false;
}
int canArrangeWords(int num, char* arr[])
{
	int i = 0;
	int* flag = new int[num];
	int j = 0;
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<num; j++)
		{
			flag[j] = 0;
		}
		flag[i] = 1;
		if (hasFollow(i, arr, flag, num))
		{
			return 1;
		}
	}
	return -1;
}
int main()
{
	char* a[] = { "sdf","gd","fg","dbc","cbc","dddas","zasd","xzzz" };
	char* b[] = { "abc","cde","ef","yg" };
	cout << canArrangeWords(8, a) << endl;
	cout << canArrangeWords(4, b) << endl;

	system("pause");
	return 0;
}
