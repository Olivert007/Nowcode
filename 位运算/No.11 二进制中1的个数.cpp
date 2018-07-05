//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
#include <cmath>
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
	int  NumberOf1(int n) {
		int count = 0;
		while (n != 0) {
			n = n&(n - 1);//n&(n - 1)可以使二进制数最右边的1变为0，所以能将几个1变为0就有几个1，直到n为全0时退出循环
			count++;
		}
		return count;
	}

	int NumberOf1_general(int n) {
		int count = 0;
		unsigned int flag = 1;//00000001
		while (flag) {
			if (n&flag)
				count++;
			flag=flag << 1;
		}
		return count;
	}
};

int  main()
{
	int num;
	Solution sol;
	while (cin >> num) {
		cout << "新解法： "<<sol.NumberOf1(num) <<" 普通解法： "<< sol.NumberOf1_general(num) << endl;
	}

	getchar();
	getchar();
	return 0;
}
