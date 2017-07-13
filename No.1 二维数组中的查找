//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include   <iostream> 
#include   <vector> 
using namespace std;

class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		// begin from the top right coner

		if (array.empty())

			return false;

		int rows = 0;

		int cols = array[0].size() - 1;//array[0].size()是列数,列数减一就是最右一行

		while (rows < array.size() && cols >= 0) {//array.size()是行数

			if (target > array[rows][cols])

				rows++;//删除第一行

			else if (target < array[rows][cols])

				cols--;//删除这一列

			else

				return true;

		}

		return false;
	}
};

int   main()
{
	vector <vector<int>>   array(3);
	for (int i = 0; i < 3; i++)
		array[i].resize(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = (i*j);

	Solution sol;

	bool hastarget;
	hastarget = sol.Find(array, 2);
	if (hastarget)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	getchar();
	return 0;

}
