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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *head = new ListNode(0), *p = head;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        while(l1)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while(l2)
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};
