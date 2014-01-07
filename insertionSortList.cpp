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
    ListNode *insertionSortList(ListNode *head) {
        if(head == 0 || head->next == 0)
            return head;
        ListNode *newhead = new ListNode(INT_MIN);
        newhead->next = head;
        ListNode *pold = head->next;
        head->next = 0;
        while(pold)
        {
            ListNode *pinsert = newhead;
            while(true)
            {
                if(pold->val == pinsert->val || pold->val > pinsert->val && (pinsert->next == 0 || pold->val <= pinsert->next->val))
                    break;
                else
                    pinsert = pinsert->next;
            }
            ListNode *ptmp = pold;
            pold = pold->next;
            ptmp->next = pinsert->next;
            pinsert->next = ptmp;
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};
