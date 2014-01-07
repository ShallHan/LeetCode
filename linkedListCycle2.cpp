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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL) return NULL;
        bool cycle = false;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(true)
        {
            if(!p1->next) break;
            if(!p2->next || !p2->next->next) break;
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)
            {
                cycle = true;
                break;
            }
        }
        if(!cycle) return NULL;
        p1 = head;
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
