//输入一个链表，反转链表后，输出链表的所有元素。

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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		ListNode *Next;
		ListNode *Pre=NULL;//当前节点
		while (pHead != NULL) {
			Next = pHead->next;//next记录当前节点的下一个节点
			pHead->next = Pre;//当前节点指向下一个节点
			Pre = pHead;//前一个节点取代当前节点
			pHead = Next;//下一个节点取代当前节点
		}
		return pre;
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
	ListNode* res=sol.ReverseList(head);
	while (res!=NULL) {
		cout << res->val << " ";
		res = res->next;
	}

	getchar();
	return 0;
}
