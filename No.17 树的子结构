//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//第一步在树A中找到和B的根节点的值一样的结点R；
//第二步再判断树A中以R为根结点的子树是不是包含和树B一样的结构。
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
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//第一步在树A中找到和B的根节点的值一样的结点R；
//第二步再判断树A中以R为根结点的子树是不是包含和树B一样的结构。
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL || pRoot1 == NULL)
			return false;
		return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}

	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL)
			return false;
		return pRoot1->val == pRoot2->val && isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
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
	bool res = sol.HasSubtree(Aroot, Broot);
	if (res)
		cout << "1";
	else
		cout << "0";

	getchar();
	return 0;
}
