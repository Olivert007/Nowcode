//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

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

class Solution {
public:
	int rectCover(int number) {
		if (number <= 0)
			return -1;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		if (number > 1)
			return rectCover(number - 1) + rectCover(number - 2);
	}
};

int main()
{
	Solution sol;
	int output;
	output = sol.rectCover(5);
	cout << output << endl;

	getchar();
	return 0;
}
