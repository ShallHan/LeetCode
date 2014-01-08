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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == 0) return 0;
        ListNode *p = new ListNode(0);
        ListNode *pslow = p;
        ListNode *pfast = head;
        while(pfast)
        {
            if( pfast->next == 0 || pfast->val != pfast->next->val)
            {
                pslow->next = pfast;
                pslow = pslow->next;
                pfast = pfast->next;
            }
            else
            {
                int tmp = pfast->val;
                while(pfast && (pfast->val == tmp))
                {
                    ListNode *ptmp = pfast;
                    pfast = pfast->next;
                    delete ptmp;
                }
            }
        }
        pslow->next = 0;
        ListNode *ptmp = p;
        p = p->next;
        delete ptmp;
        return p;
    }
};
