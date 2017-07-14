//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

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
	int jumpFloorII(int number) {
		if (number <= 0)
			return -1;
		if (number == 1)
			return 1;
		if (number > 1)
			//第一次跳一阶，余下的台阶有jumpFloorII(n-1)种跳法
			//第一次跳两阶，余下的台阶有junpFloorII(n-2)种跳法
			//所以jumpFloorII(n)=jumpFloorII(n-1)+jumpFloorII(n-2)+...+jumpFloorII(1)
			//所以jumpFloorII(n-1)=jumpFloorII(n-2)+jumpFloorII(n-3)+...+jumpFloorII(1)
			//所以jumpFloorII(n)=jumpFloorII(n-1)+jumpFloorII(n-1)
			return jumpFloorII(number - 1) * 2;
	}
};

int   main()
{
	Solution sol;
	int output;
	output = sol.jumpFloorII(5);
	cout << output << endl;

	getchar();
	return 0;
}
