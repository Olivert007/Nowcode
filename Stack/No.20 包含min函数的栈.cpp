//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
#define MIN(a,b) ((a)<(b)?(a):(b))
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
	stack<pair<int, int>> s;
	void push(int value) {
		s.push(pair<int, int>(value, s.empty() ? value : MIN(value, min())));
	}
	void pop() {
		s.pop();
	}
	int top() {
		return s.top().first;
	}
	int min() {
		return s.top().second;
	}
};

int main()
{
	Solution sol;
	sol.push(1);
	sol.push(3);
	sol.push(5);
	cout << sol.min();


	getchar();
	return 0;
}
