//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode* node;
		
		if (pHead1->val < pHead2->val) {
			node = pHead1;
			node->next = Merge(pHead1->next, pHead2);
		}
		else {
			node = pHead2;
			node->next = Merge(pHead1, pHead2->next);
		}
		return node;

	}
};

int main()
{
	ListNode* head = new ListNode(0);
	ListNode* node1 = new ListNode(2);
	head->next=node1;
	ListNode* node2 = new ListNode(4);
	node1->next = node2;
	ListNode* node3 = new ListNode(6);
	node2->next = node3;
	ListNode* node4 = new ListNode(8);
	node3->next = node4;
	ListNode* node5 = new ListNode(10);
	node4->next = node5;

	ListNode* head_ = new ListNode(1);
	ListNode* node1_ = new ListNode(3);
	head_->next = node1_;
	ListNode* node2_ = new ListNode(5);
	node1_->next = node2_;
	ListNode* node3_ = new ListNode(7);
	node2_->next = node3_;
	ListNode* node4_ = new ListNode(9);
	node3_->next = node4_;
	ListNode* node5_ = new ListNode(11);
	node4_->next = node5_;

	Solution sol;
	ListNode* res = sol.Merge(head, head_);
	while (res!=NULL) {
		cout << res->val << " ";
		res = res->next;
	}

	getchar();
	return 0;
}
