//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

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
	int jumpFloor(int number) {
		if (number <= 0)
			return -1;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		if (number > 2)
			return jumpFloor(number - 1) + jumpFloor(number - 2);//第一次跳一下，剩下的就有jumpFloor(number - 1)种跳法，
			//第一次跳两下，剩下的就有jumpFloor(number - 2)种跳法
	}
};

int   main()
{
	Solution sol;
	int output;
	output = sol.jumpFloor(5);
	cout << output << endl;

	getchar();
	return 0;
}
