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
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == 0) return;
        if(root->left == 0 && root->right == 0) return;
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        else
            root->right->next = 0;
        connect(root->left);
        connect(root->right);
    }
};
