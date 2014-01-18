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
    ListNode *swapPairs(ListNode *head) {
        if(head == 0) return 0;
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode *p1 = head, *p2 = head;
        while(p->next && p->next->next)
        {
            p1 = p->next;
            p2 = p1->next;
            ListNode *tmp = p2->next;
            p->next = p2;
            p2->next = p1;
            p1->next = tmp;
            p = p1;
        }
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};
