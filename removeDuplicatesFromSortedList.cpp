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
        ListNode *pslow = head;
        ListNode *pfast = head->next;
        while(pfast)
        {
            if(pfast->val == pslow->val)
            {
                ListNode *ptmp = pfast;
                pfast = pfast->next;
                delete ptmp;
            }
            else
            {
                pslow->next = pfast;
                pslow = pslow->next;
                pfast = pfast->next;
            }
        }
        pslow->next = 0;
        return head;
    }
};
