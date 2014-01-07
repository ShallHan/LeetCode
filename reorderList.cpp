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
    ListNode* findMiddlePointer(ListNode *head)
    {
        int len = 0;
        ListNode *p = head;
        while(p)
        {
            ++len;
            p = p->next;
        }
        p = head;
        for(int i = 1; i < len/2; ++i)
        {
            p = p->next;
        }
        return p;
    }
    ListNode* reverse(ListNode *head)
    {
        if(head == 0) return 0;
        ListNode *pnew = 0, *pold = head;
        while(pold)
        {
            ListNode *p = pold;
            pold = pold->next;
            p->next = pnew;
            pnew = p;
        }
        return pnew;
    }
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == 0 || head->next == 0) return;
        ListNode *pmiddle = findMiddlePointer(head);
        ListNode *ptmp = pmiddle->next;
        pmiddle->next = 0;
        pmiddle = ptmp;
        ListNode *p2 = reverse(pmiddle);
        ListNode *p1 = head;
        head = new ListNode(0);
        ListNode *p = head;
        while(p1 && p2)
        {
            ptmp = p1;
            p1 = p1->next;
            p->next = ptmp;
            p = p->next;
            ptmp = p2;
            p2 = p2->next;
            p->next = ptmp;
            p = p->next;
        }
        if(p2)
        {
            p->next = p2;
        }
        ptmp = head;
        head = head->next;
        delete ptmp;
    }
};
