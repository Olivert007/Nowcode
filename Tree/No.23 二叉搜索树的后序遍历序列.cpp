//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
#include <iostream>
#include <vector>

using namespace std;
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
//int data[] = { 4, 8, 6, 12, 16, 14, 10 };

class Solution {
public:
	bool VerifySquenceOfBST_Core(int sequence[], int length) {
		if (sequence == nullptr || length <= 0)
			return false;

		int root = sequence[length - 1];

		// 在二叉搜索树中左子树的结点小于根结点
		int i = 0;
		for (; i < length - 1; i++)
		{
			if (sequence[i] > root)
				break;
		}

		// 在二叉搜索树中右子树的结点大于根结点
		int j = i;
		for (; j < length - 1; j++)
		{
			if (sequence[j] < root)
				return false;
		}

		// 判断左子树是不是二叉搜索树
		bool left = true;
		if (i > 0)
			left = VerifySquenceOfBST_Core(sequence, i);

		// 判断右子树是不是二叉搜索树
		bool right = true;
		if (i < length - 1)
			right = VerifySquenceOfBST_Core(sequence + i, length - i - 1);

		return (left && right);
	}

	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		int size = sequence.size();
		int* a_sequence = new int[size];
		for (int i = 0; i < size; i++)
			a_sequence[i] = sequence[i];
		return VerifySquenceOfBST_Core(a_sequence, sequence.size());
	}
};

int  main()
{
	vector<int> push={ 4, 8, 6, 12, 16, 14, 10 };
	
	Solution sol;
	if (sol.VerifySquenceOfBST(push))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	getchar();
	return 0;
}
