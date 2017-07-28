//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

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

class Solution {
public:
	struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		int in_length = in.size();
		if (in_length == 0 || pre.size()==0)
			return NULL;
		int root_pos=0;
		vector<int> left_pre, right_pre, left_in, right_in;
		TreeNode* root = new TreeNode(pre[0]);

		for (int i = 0; i < in.size(); i++) {
			if (in[i] == pre[0]) {
				root_pos = i;
				break;
			}
		}
		for (int i = 0; i < root_pos; i++) {
			left_in.push_back(in[i]);
			left_pre.push_back(pre[i + 1]);
		}
		for (int i = root_pos + 1; i < in_length; i++) {
			right_in.push_back(in[i]);
			right_pre.push_back(pre[i]);
		}
		root->left = reConstructBinaryTree(left_pre, left_in);
		root->right = reConstructBinaryTree(right_pre, right_in);

		return root;
	}
};

void PrintTreeNode(const TreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->val);

		if (pNode->left!= nullptr)
			printf("value of its left child is: %d.\n", pNode->left->val);
		else
			printf("left child is nullptr.\n");

		if (pNode->right != nullptr)
			printf("value of its right child is: %d.\n", pNode->right->val);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}
	printf("\n");
}

void PrintTree(const TreeNode* pRoot) {
	PrintTreeNode(pRoot);
	if (pRoot != nullptr) {
		if (pRoot != nullptr) {
			if (pRoot->left != nullptr)
				PrintTree(pRoot->left);
			if (pRoot->right != nullptr)
				PrintTree(pRoot->right);
		}
	}
}

int main()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int>pre, in;
	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i) {
		pre.push_back(preorder[i]);
		printf("%d ", preorder[i]);
	}
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i) {
		in.push_back(inorder[i]);
		printf("%d ", inorder[i]);
	}
	printf("\n");

	Solution sol;
	try
	{
		TreeNode* root = sol.reConstructBinaryTree(pre,in);
		PrintTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}

	getchar();
	return 0;

}
