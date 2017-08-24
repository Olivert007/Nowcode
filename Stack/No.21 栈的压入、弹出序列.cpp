//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
//但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
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
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0) return false;
		vector<int> stack;
		for (int i = 0, j = 0; i < pushV.size();) {
			stack.push_back(pushV[i++]);
			while (j < popV.size() && stack.back() == popV[j]) {
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();//如果是空，则返回ture,即表示是正确的弹出序列
							 //基本思想是：如果它是出栈顺序的话，我可以按照出栈的方式把栈里元素全部出完。
	}
};

int main()
{
	vector<int> a,b;
	a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4); a.push_back(5);
	b.push_back(4); b.push_back(5); b.push_back(3); b.push_back(2); b.push_back(1);//测试用例，返回1
	Solution sol;
	if (sol.IsPopOrder(a, b))
		cout << "1";
	else
		cout << "0";
	getchar();
	return 0;
}
