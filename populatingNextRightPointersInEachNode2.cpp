/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* find_next(TreeLinkNode *root){
        if(root==0) return 0;
        if(root->next==0) return 0;
        TreeLinkNode *p = root->next;
        while(p)
        {
            if(p->left) return p->left;
            if(p->right) return p->right;
            p = p->next;
        }
        return 0;
    }
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root==0) return;
        if(root->left==0 && root->right==0) return;
        if(root->left && root->right) 
        {
            root->left->next = root->right;
            root->right->next = find_next(root);
            
            connect(root->right);
            connect(root->left);
        }
        else if(root->left)
        {
            root->left->next = find_next(root);
            connect(root->left);
        }
        else
        {
            root->right->next = find_next(root);
            connect(root->right);
        }
    }
};
