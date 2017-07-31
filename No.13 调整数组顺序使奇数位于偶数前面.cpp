//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

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
	void reOrderArray(vector<int> &array) {
		vector<int> b;
		int length = array.size();
		for (int i = 0; i < length; i++) {//奇数在前面
			if (array[i] % 2 != 0)
				b.push_back(array[i]);
		}
		for (int i = 0; i < length; i++) {//奇数在前面
			if (array[i] % 2 == 0)
				b.push_back(array[i]);
		}
		array.assign(b.begin(),b.end());
	}
};

int main()
{
	Solution sol;
	vector<int> a = { 2,7,20,1,4,5,2 };
	sol.reOrderArray(a);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	getchar();
	return 0;
}
