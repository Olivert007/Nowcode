//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方

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
	double Power(double base, int exponent) {
		double base_begin;
		base_begin = base;
		if (exponent > 0) {
			while ((--exponent) > 0) {
				base *= base_begin;
			}
			return base;
		}
		else if (exponent < 0) {
			while ((++exponent) < 0) {
				base *= base_begin;
			}
			return 1 / base;
		}
		else
			return 1;
	}
};

int main()
{
	Solution sol;
	double res;
	res=sol.Power(2, -3);
	cout << res << endl;
	getchar();
	return 0;
}
