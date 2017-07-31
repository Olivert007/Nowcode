//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。(位运算)

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
	//把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
	int  NumberOf1(int n) {
		int count = 0;
		while (n != 0) {
			n = n&(n - 1);
			count++;
		}
		return count;
	}
};

int main()
{
	Solution sol;
	int output;
	output = sol.NumberOf1(7);
	cout << output << endl;

	getchar();
	return 0;
}
