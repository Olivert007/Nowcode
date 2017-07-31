//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n <= 39

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
	int Fibonacci(int n) {
		int pre = 1;
		int cur = 0;
		while (n-- > 0) {
			pre = pre + cur;
			cur = pre - cur;
		}
		return cur;
	}
};

int   main()
{
	Solution sol;
	int output;
	output = sol.Fibonacci(6);
	cout << output << endl;

	getchar();
	return 0;

}
