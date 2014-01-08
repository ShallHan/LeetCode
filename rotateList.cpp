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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == 0)
            return 0;
        int len = 1;
        ListNode *p = head;
        while(p->next)
        {
            ++len;
            p = p->next;
        }
        ListNode *tail = p;
        k = k % len;
        if(k == 0) return head;
        int m = len - k;
        p = head;
        for(int i = 1; i < m; ++i)
        {
            p = p->next;
        }
        tail->next = head;
        head = p->next;
        p->next = 0;
        return head;
    }
};
