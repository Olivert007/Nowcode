//输入一个链表，从尾到头打印链表每个节点的值。
//
#include   <iostream> 
#include   <vector> 
#include <string>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> dayin;
		while (head != NULL)
		{
			dayin.insert(dayin.begin(), head->val);
			head = head->next;
		}
		return dayin;
	}
};

int   main()
{
	ListNode *head = new ListNode(0);
	ListNode *node1= new ListNode(1);
	ListNode *node2= new ListNode(2);
	ListNode *node3= new ListNode(3);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;

	Solution sol;
	vector<int> a;
	a=sol.printListFromTailToHead(head);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}

	getchar();
	return 0;

}
