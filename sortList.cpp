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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(left && right)
        {
            if(left->val <= right->val)
            {
                ListNode *ptmp = left;
                left = ptmp->next;
                p->next = ptmp;
                p = p->next;
            }
            else
            {
                ListNode *ptmp = right;
                right = ptmp->next;
                p->next = ptmp;
                p = p->next;
            }
        }
        if(left)
            p->next = left;
        if(right)
            p->next = right;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
    ListNode *sortList(ListNode *head) 
    {
        if(head == 0 || head->next == 0)
            return head;
        int len = 0;
        ListNode *p = head;
        while(p)
        {
            ++len;
            p = p->next;
        }
        p = head;
        for(int i = 1; i < len / 2; ++i)
        {
            p = p->next;
        }
        ListNode *left = head;
        ListNode *right = p->next;
        p->next = 0;
        left = sortList(left);
        right = sortList(right);
        ListNode *res = merge(left, right);
        return res;
    }
};
