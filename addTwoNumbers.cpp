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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(l1 == 0 && l2 == 0) return 0;
        int carry = 0;
        ListNode *phead = new ListNode(0), *pnow = phead;
        for(;l1!=0 && l2!=0;l1=l1->next, l2=l2->next)
        {
            int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            ListNode *p = new ListNode(tmp%10);
            pnow->next = p;
            pnow = p;
            
        }
        for(;l1!=0;l1=l1->next)
        {
            int tmp = l1->val + carry;
            ListNode *p = new ListNode(tmp%10);
            carry = tmp/10;
            pnow->next = p;
            pnow = p;
        }
        for(;l2!=0;l2=l2->next)
        {
            int tmp = l2->val + carry;
            ListNode *p = new ListNode(tmp % 10);
            carry = tmp/10;
            pnow->next = p;
            pnow = p;
        }
        if(carry != 0)
        {
            ListNode *p = new ListNode(carry);
            pnow->next = p;
            pnow = p;
        }
        ListNode *p = phead->next;
        delete phead;
        return p;
    }
};
