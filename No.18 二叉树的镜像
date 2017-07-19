//操作给定的二叉树，将其变换为源二叉树的镜像。
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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;
		TreeNode* tmp;
		//交换
		if (pRoot->left&&pRoot->right) {
			tmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmp;
		}
		//遍历
		if (pRoot->left)
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
	}
};

int main()
{
	TreeNode* Aroot = new TreeNode(8);
	TreeNode* Anode1 = new TreeNode(8);
	TreeNode* Anode2 = new TreeNode(7);
	TreeNode* Anode3 = new TreeNode(9);
	TreeNode* Anode4 = new TreeNode(2);
	TreeNode* Anode5 = new TreeNode(4);
	TreeNode* Anode6 = new TreeNode(7);
	Aroot->left = Anode1;
	Aroot->right = Anode2;
	Anode1->left = Anode3;
	Anode1->right = Anode4;
	Anode4->left = Anode5;
	Anode4->right = Anode6;

	TreeNode* Broot = new TreeNode(8);
	TreeNode* Bnode1 = new TreeNode(9);
	TreeNode* Bnode2 = new TreeNode(2);
	Broot->left = Bnode1;
	Broot->right = Bnode2;

	Solution sol;
	sol.Mirror(Aroot);

	getchar();
	return 0;
}
