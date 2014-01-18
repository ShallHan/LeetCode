struct OrderListNode
{
    bool operator() (ListNode *a, ListNode *b)
    {
    	return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
	priority_queue<ListNode*, vector<ListNode*>, OrderListNode> q;
	for(int i = 0; i < lists.size(); ++i)
	{
		if(lists[i])
			q.push(lists[i]);
	}
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	while(!q.empty())
	{
		ListNode *tmp = q.top();
		q.pop();
		p->next = tmp;
		p = p->next;
		if(tmp->next)
			q.push(tmp->next);
	}
	p->next = 0;
	p = head;
	head = head->next;
	delete p;
	return head;
    }
};
