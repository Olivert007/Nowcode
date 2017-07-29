//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

#include   <iostream> 
#include   <vector> 
#include   <string>
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

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}
	int pop() {
		int a;
		if (!stack1.empty()) {
			a = stack1.top();
		}
		if (stack2.empty()) {
			while (!stack1.empty()) {
				a = stack1.top();
				stack1.pop();
				stack2.push(a);
			}
			a = stack2.top();
			stack2.pop();
			return a;
		}
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

int   main()
{
	stack<int> pre;
	stack<int> in;

	Solution sol;
	sol.push(1);
	sol.push(2);
	sol.push(3);
	cout<<sol.pop();

	getchar();
	return 0;

}
