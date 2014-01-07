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
    TreeNode* traversal(TreeNode *root){
        if(root == 0) return 0;
        if(root->left==0&&root->right==0) return root;
        TreeNode *pleft = traversal(root->left);
        TreeNode *pright = traversal(root->right);
        if(pleft && pright)
        {
            TreeNode *ptmp = root->right;
            root->right = root->left;
            pleft->right = ptmp;
            root->left = 0;
            return pright;
        }
        if(pleft)
        {
            root->right = root->left;
            root->left = 0;
            return pleft;
        }
        if(pright)
        {
            return pright;
        }
        
    }
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        traversal(root);
    }
};
