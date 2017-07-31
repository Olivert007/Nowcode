//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

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
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length < 0)
			return false;
		vector<int> hash(length, 0);
		for (int i = 0; i < length; i++) {
			hash[numbers[i]]++;
			if (hash[numbers[i]] > 1) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution sol;
	int duplication;
	int numbers[] = { 2,3,1,0,2,5,3 };
	bool validInput = sol.duplicate(numbers, sizeof(numbers)/sizeof(int), &duplication);
	if (validInput) {
		cout << duplication;
		cout << "ture";
	}
	else
		cout << "false";

	getchar();
	return 0;
}
