/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head, int len)
    {
        if(head == 0 || len == 0) return 0;
        ListNode *pmiddle = head;
        for(int i = 0; i < len/2; ++i)
            pmiddle = pmiddle->next;
        TreeNode *pres = new TreeNode(pmiddle->val);
        pres->left = sortedListToBST(head, len/2);
        pres->right = sortedListToBST(pmiddle->next, len - len/2 - 1);
        return pres;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == 0) return 0;
        ListNode *p = head;
        int len = 0;
        while(p)
        {
            ++len;
            p = p->next;
        }
        return sortedListToBST(head, len);
    }
};
