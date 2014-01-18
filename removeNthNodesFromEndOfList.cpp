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
    ListNode *removeNthFromEnd(ListNode *phead, int n) {
        ListNode *head = new ListNode(0);
        head->next = phead;
        ListNode *p1 = head, *p2 = head;
        for(int i = 1; i <= n; ++i)
        {
            p2 = p2->next;
        }
        while(p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *p = p1->next;
        p1->next = p->next;
        delete p;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};
