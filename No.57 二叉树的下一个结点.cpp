//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

#include <iostream> 
#include <vector> 
#include <string>
using namespace std;
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		if (pNode == NULL)
			return NULL;
		TreeLinkNode* res_next = NULL;
		//第一种情况,节点有右子树
		if (pNode->right != NULL) {
			TreeLinkNode* right = pNode->right;
			while (right->left != NULL) {
				right = right->left;//直到找到右子树中的最左子节点
			}
			res_next = right;
		}
		else if (pNode->next != NULL) {//没有右子树
			TreeLinkNode* pCur = pNode;
			TreeLinkNode* pParent = pNode->next;
			if (pParent != NULL&&pCur == pParent->left)//第二种情况。没有右子树，并且是父节点的左子树，则下一节点是父节点
				res_next = pParent;
			while((pParent!= NULL)&&pCur == pParent->right) {//第三种情况。没有右子树，并且是父节点的右子树，则下一个节点是向上找到一个“父节点是左孩子的节点”的父节点
				pCur = pParent;
				pParent = pParent->next;
			}
			res_next = pParent;
		}
		return res_next;
	}
};

TreeLinkNode* CreateBinaryTreeNode(int value)
{
	TreeLinkNode* pNode = new TreeLinkNode(value);
	pNode->val = value;
	pNode->left = nullptr;
	pNode->right = nullptr;
	pNode->next = nullptr;
	return pNode;
}

void ConnectTreeNodes(TreeLinkNode* pParent, TreeLinkNode* pLeft, TreeLinkNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;

		if (pLeft != nullptr)
			pLeft->next = pParent;
		if (pRight != nullptr)
			pRight->next = pParent;
	}
}

int main()
{
	//            8
	//        6      10
	//       5 7    9  11
	TreeLinkNode* pNode8 = CreateBinaryTreeNode(8);
	TreeLinkNode* pNode6 = CreateBinaryTreeNode(6);
	TreeLinkNode* pNode10 = CreateBinaryTreeNode(10);
	TreeLinkNode* pNode5 = CreateBinaryTreeNode(5);
	TreeLinkNode* pNode7 = CreateBinaryTreeNode(7);
	TreeLinkNode* pNode9 = CreateBinaryTreeNode(9);
	TreeLinkNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Solution sol;
	TreeLinkNode* res;
	res=sol.GetNext(pNode6);//改变节点来验证
	cout << res->val;
	getchar();
	return 0;

}
