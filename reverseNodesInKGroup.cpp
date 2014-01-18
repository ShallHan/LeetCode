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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == 0) return 0;
	if(k <= 1) return head;
	ListNode *newhead = new ListNode(0);
	newhead->next = head;
	ListNode *p = newhead;
	while(true)
	{
		ListNode *tmp = p->next;
		bool end = false;
		for(int i = 0; i < k; ++i)
		{
			if(tmp == 0)
			{
				end = true;
				break;
			}
			tmp = tmp->next;
		}
		if(end)
			break;
		ListNode *thead = new ListNode(0);
		ListNode *tp = p->next;
		ListNode *last = p->next;
		for(int i = 0; i < k; ++i)
		{
			tmp = tp->next;
			tp->next = thead->next;
			thead->next = tp;
			tp = tmp;
		}
		tmp = thead;
		thead = thead->next;
		p->next = thead;
		delete tmp;
		p = last;
		last->next = tp;
	}
	ListNode *tmp = newhead;
	newhead = newhead->next;
	delete tmp;
	return newhead;
    }
};
