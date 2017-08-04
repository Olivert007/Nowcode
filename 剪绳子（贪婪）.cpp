#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
#include <cmath>
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

int maxres(int length) {
	if (length == 1)return 0;
	if (length == 2)return 1;
	if (length == 3)return 2;

	int timeOf3 = length / 3;
	if (length - timeOf3 * 3 == 1)
		timeOf3--;
	int timeOf2 = (length - 3 * timeOf3) / 2;
	return pow(3, timeOf3)*pow(2, timeOf2);
}

int  main()
{
	int length;
	while (cin >> length) {
		cout << maxres(length) << endl;
	}
	getchar();
	return 0;
}
