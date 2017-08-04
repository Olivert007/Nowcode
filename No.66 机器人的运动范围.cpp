//地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格（35, 37），因为3 + 5 + 3 + 7 = 18。
//但是，它不能进入方格（35, 38），因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子？

#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;

		//bool *visited = new bool[rows * cols];
		//for (int i = 0; i < rows * cols; ++i)
		//	visited[i] = false;
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));

		int count = movingCountCore(threshold, rows, cols,
			0, 0, visited);

		//delete[] visited;

		return count;
	}

	int movingCountCore(int threshold, int rows, int cols, int row,
		int col, vector<vector<bool>> &visited)//要改变visited值，注意用引用
	{
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited))
		{
			visited[row][col] = true;

			count = 1 + movingCountCore(threshold, rows, cols,
				row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols,
					row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols,
					row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols,
					row, col + 1, visited);
		}

		return count;
	}

	bool check(int threshold, int rows, int cols, int row, int col,
		vector<vector<bool>> visited)
	{
		if (row >= 0 && row < rows && col >= 0 && col < cols
			&& getDigitSum(row) + getDigitSum(col) <= threshold
			&& !visited[row][col])
			return true;

		return false;
	}

	int getDigitSum(int number)
	{
		int sum = 0;
		while (number > 0)
		{
			sum += number % 10;
			number /= 10;
		}

		return sum;
	}
};

int  main()
{
	Solution sol;
	int k,rows,cols;
	while (cin >> k>>rows>>cols) {
		cout << sol.movingCount(k, rows, cols);
	}
	getchar();
	return 0;
}
