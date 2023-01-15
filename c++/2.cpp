class Solution
{
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
		{
			ListNode *head = l1;
			while (l1->next && l2->next)
			{
				l1->val += l2->val;
				if (l1->val >= 10)
				{
					l1->val -= 10;
					l1->next->val += 1;
				}
				l1 = l1->next;
				l2 = l2->next;
			}
			if (l2->next)
				l1->next = l2->next;
			l1->val += l2->val;
			while (l1->next)
			{
				if (l1->val >= 10)
				{
					l1->val -= 10;
					l1->next->val += 1;
				}
				l1 = l1->next;
			}
			if (l1->val >= 10)
			{
				l1->val -= 10;
				l1->next = new ListNode(1);
			}
			return head;
		}
};

