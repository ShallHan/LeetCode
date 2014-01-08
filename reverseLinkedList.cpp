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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        int idx = 1;
        ListNode *pm = newhead;
        for(; idx < m; ++idx)
        {
            pm = pm->next;
        }
        ListNode *pn = pm->next;
        ListNode *pold = pm->next;
        pm->next = 0;
        for(int i = 0; i <= n-m; ++i)
        {
            ListNode *ptmp = pold;
            pold = pold->next;
            ptmp->next = pm->next;
            pm->next = ptmp;
        }
        pn->next = pold;
        head = newhead->next;
        delete newhead;
        return head;
    }
};
