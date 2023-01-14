class Solution {
	public:
		ListNode* middleNode(ListNode* head) {
            ListNode *ptr1 = head, *ptr2 = head;
            while (ptr2->next)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                if (ptr2->next)
                    ptr2 = ptr2->next;
            }
            return ptr1;
		}
};

