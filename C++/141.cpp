/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		bool hasCycle(ListNode *head) {
			if (!head || !head->next)
				return false;
			ListNode *slow = head, *fast = head;
			while(slow->next)
			{
				slow = slow->next;
				fast = fast->next;
				if (fast && fast->next)
				{
					fast = fast->next;
					if (fast == slow)
						return true;
				}
				else
					return false;
			}
			return false;
		}
};

