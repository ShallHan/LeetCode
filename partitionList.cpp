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
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == 0 || head->next == 0) return head;
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(0);
        ListNode *p1 = small;
        ListNode *p2 = large;
        ListNode *p = head;
        while(p)
        {
            if(p->val >= x)
            {
                p2->next = p;
                p = p->next;
                p2 = p2->next;
            }
            else
            {
                p1->next = p;
                p = p->next;
                p1 = p1->next;
            }
        }
        p1->next = large->next;
        p2->next = 0;
        head = small->next;
        delete small;
        delete large;
        return head;
    }
};
