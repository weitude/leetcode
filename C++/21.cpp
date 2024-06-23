/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			ListNode node = ListNode();
			ListNode *head=  &node;
			ListNode *dummy = head;
			ListNode *ptr1 = list1;
			ListNode *ptr2 = list2;
			while (true) {
				if (ptr1 == nullptr && ptr2 == nullptr)
					break;
				if (ptr2 == nullptr || (ptr1 && ptr1->val < ptr2->val)) {
					head->next = ptr1;
					ptr1 = ptr1->next;
				} else {
					head->next = ptr2;
					ptr2 = ptr2->next;
				}
				head = head->next;
			}
			return dummy->next;
		}
};

