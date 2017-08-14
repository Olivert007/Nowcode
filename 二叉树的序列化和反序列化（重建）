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

void DestoryTree(BinaryTreeNode* pRoot) {
	if (pRoot != nullptr) {
		BinaryTreeNode* pLeft = pRoot->left;
		BinaryTreeNode* pRight = pRoot->right;
		delete pRoot;
		pRoot = nullptr;

		DestoryTree(pRoot->left);
		DestoryTree(pRoot->right);
	}
}

bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

void Serialize(const BinaryTreeNode* pRoot, ostream &stream) {
	if (pRoot == nullptr) {
		cout << "$,";
		return;
	}
	cout << pRoot->val << ",";
	Serialize(pRoot->left, stream);
	Serialize(pRoot->right, stream);
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode();
		(*pRoot)->val = number;
		(*pRoot)->left = nullptr;
		(*pRoot)->right = nullptr;

		Deserialize(&((*pRoot)->left), stream);
		Deserialize(&((*pRoot)->right), stream);
	}
}

int main() {
	char* fileName = "text.txt";
	ofstream ofile;
	ofile.open(fileName);

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
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Serialize(pNode8, ofile);
	ofile.close();

	// print the serialized file
	ifstream ifile;
	char ch;
	ifile.open(fileName);
	while (!ifile.eof()) {
		ifile >> ch;
		cout << ch;
	}
	ifile.close();
	cout << endl;

	ifstream ifile2;
	ifile2.open(fileName);
	BinaryTreeNode* pNewRoot = nullptr;
	Deserialize(&pNewRoot, ifile2);
	ifile2.close();
	
	DestoryTree(pNewRoot);

	getchar();
}
