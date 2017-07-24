//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
//如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
using namespace std;


class ListNode {
public:
	int val;
	class ListNode * next;
	ListNode(int x) :val(x), next(NULL) {}
};



//Definition for binary tree
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		res.resize(16);
		int row = matrix.size();
		int col = matrix[0].size();

		if (row == 0 || col == 0)
			return res;

		int top = 0;
		int left = 0;
		int bottom = row - 1;
		int right = col - 1;

		while (top <= bottom && left <= right)
		{
			for (int i = left; i <= right; i++)
				res.push_back(matrix[top][i]);
			for (int i = top + 1; i <= bottom; i++)
				res.push_back(matrix[i][right]);
			if (top != bottom)
				for (int i = right-1; i >= left; i--)
					res.push_back(matrix[bottom][i]);
			if (left != right)
				for (int i = bottom-1; i > top; i--)
					res.push_back(matrix[i][left]);
			left++; right--; top++; bottom--;
		}

		return res;
	}
};

int main()
{
	vector<vector<int>> mat;
	mat.resize(4);
	for (int i = 0; i < 4; i++) {
		mat[i].resize(4);
	}
	mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3; mat[0][3] = 4;
	mat[1][0] = 5; mat[1][1] = 6; mat[1][2] = 7; mat[1][3] = 8;
	mat[2][0] = 9; mat[2][1] = 10; mat[2][2] = 11; mat[2][3] = 12;
	mat[3][0] = 13; mat[3][1] = 14; mat[3][2] = 15; mat[3][3] = 16;

	//mat[0].push_back(1); mat[0].push_back(2); mat[0].push_back(3); mat[0].push_back(4);
	//mat[1].push_back(5); mat[1].push_back(6); mat[1].push_back(7); mat[1].push_back(8);
	//mat[2].push_back(9); mat[2].push_back(10); mat[2].push_back(11); mat[2].push_back(12);
	//mat[3].push_back(13); mat[3].push_back(14); mat[3].push_back(15); mat[3].push_back(16);

	Solution sol;
	vector<int> res;
	res.resize(16);
	res=sol.printMatrix(mat);

	for (int i = 0; i < res.size(); i++) {
		if(res[i]!=0)
			cout << res[i] << " ";
	}

	getchar();
	return 0;
}
