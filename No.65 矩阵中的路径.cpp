//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
//但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
//路径不能再次进入该格子。

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
	bool hasPathCore(const char* matrix, int rows, int cols, int row,
		int col, const char* str, int pathLength, vector<vector<bool>> visited)
	{
		if (str[pathLength] == '\0')
			return true;

		bool hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols
			&& matrix[row * cols + col] == str[pathLength]
			&& !visited[row][col])
		{
			++pathLength;
			visited[row][col] = true;

			hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
				str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row - 1, col,
					str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1,
					str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col,
					str, pathLength, visited);

			if (!hasPath)//四面都不行的话，就回溯
			{
				--pathLength;
				visited[row][col] = false;
			}
		}
		return hasPath;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (str == NULL || matrix == NULL || rows < 1 || cols < 1)
			return false;
		//int pathLength = 0;
		vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (hasPathCore(matrix, rows, cols, row, col, str, 0, visited)) {
					return true;
				}
			}
		}
		vector<vector<bool>>(visited).swap(visited);
		return false;
	}
};

int   main()
{
	//ABTG
	//CFCS
	//JDEH
	Solution sol;
	char* matrix = "ABTGCFCSJDEH";
	//char* str = "BFCEHSGTJ";
	char* str;
	char array[100];
	str = array;
	bool res;

	while (cin >> str) {
		res = sol.hasPath(matrix, 3, 4, str);
		if (res)
			cout << "has path" << endl;
		else
			cout << "No" << endl;
	}
	getchar();
	return 0;
}
