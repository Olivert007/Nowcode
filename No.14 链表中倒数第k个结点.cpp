//输入一个链表，输出该链表中倒数第k个结点

#include <iostream> 
#include <vector> 
#include <string>
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

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)
			return NULL;
		//用一个vector来保存节点，最后返回a[a.size()-k]
		vector<ListNode *>list;
		ListNode* node;
		node = pListHead;
		while (node!=NULL) {
			list.push_back(node);
			node = node->next;
		}
		return list[list.size() - k];
	}
};

int main()
{
	ListNode* head = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	head->next=node1;
	ListNode* node2 = new ListNode(2);
	node1->next = node2;
	ListNode* node3 = new ListNode(3);
	node2->next = node3;
	ListNode* node4 = new ListNode(4);
	node3->next = node4;
	ListNode* node5 = new ListNode(5);
	node4->next = node5;

	Solution sol;
	ListNode* res;
	res=sol.FindKthToTail(head,3);
	cout << res->val << endl;
	getchar();
	return 0;
}
