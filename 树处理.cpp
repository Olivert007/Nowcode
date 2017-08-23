#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->val = value;
	pNode->left = nullptr;
	pNode->right = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}

BinaryTreeNode* Inorder(BinaryTreeNode* pRoot, int &k) {
	BinaryTreeNode* target = nullptr;

	if (pRoot->left != nullptr)
		target = Inorder(pRoot->left, k);

	if (target == nullptr)
	{
		if (k == 1)
			target = pRoot;

		k--;
	}

	if (target == nullptr && pRoot->right != nullptr)
		target = Inorder(pRoot->right, k);

	return target;
}

void Inorder(BinaryTreeNode* root) {
	if (root != nullptr) {
		Inorder(root->left);
		cout << root->val << " ";
		Inorder(root->right);
	}
}

int DepthOfTree(BinaryTreeNode* root) {
	if (root==nullptr)
		return 0;
	int DepOfLeft = DepthOfTree(root->left);
	int DepOfRight = DepthOfTree(root->right);
	return DepOfLeft > DepOfRight ? (DepOfLeft + 1) : (DepOfRight + 1);
}

bool isBalance(BinaryTreeNode* root) {
	if (root == nullptr)
		return true;
	int DepOfLeft = DepthOfTree(root->left);
	int DepOfRight = DepthOfTree(root->right);
	if (DepOfLeft - DepOfRight > 1 || DepOfLeft - DepOfRight < -1)
		return false;
	return isBalance(root->left) && isBalance(root->right);
}

bool isBalancePost(BinaryTreeNode* root, int& depth) {
	if (root == nullptr) {
		depth = 0;
		return true;
	}
	int left, right;
	if (isBalancePost(root->left, left) && isBalancePost(root->right, right)) {
		if (DepthOfTree(root->left) - DepthOfTree(root->right) <= 1 ||
			DepthOfTree(root->left) - DepthOfTree(root->right) >= -1) {
			depth= DepthOfTree(root->left)>DepthOfTree(root->right)? DepthOfTree(root->left):DepthOfTree(root->right);
			++depth;
			return true;
		}
	}
	return false;
}

int main() {
	
	//            8
	//        6      10
	//       5 7    9  11
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, nullptr);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	int k = 1;
	BinaryTreeNode* pNode = Inorder(pNode8, k);
	cout << pNode->val << endl;
	Inorder(pNode8);

	cout << endl << DepthOfTree(pNode8) << endl;

	if (isBalance(pNode8))
		cout << "是平衡树" << endl;
	else
		cout << "不是平衡树" << endl;

	int depth = 0;
	if (isBalancePost(pNode8, depth))
		cout << "是平衡树" << endl;
	else
		cout << "不是平衡树" << endl;

	system("pause");
	return 0;
}
