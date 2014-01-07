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
    bool isValidBST(TreeNode *root, int &min, int &max) {
        if(root == 0) return true;
        min = root->val;
        max = root->val;
        if(root->left)
        {
            if(root->val <= root->left->val)
                return false;
            int lmin = 0, lmax = 0;
            if(!isValidBST(root->left, lmin, lmax) || root->val <= lmax)
                return false;
            min = lmin;
        }
        if(root->right)
        {
            if(root->val >= root->right->val)
                return false;
            int rmin = 0, rmax = 0;
            if(!isValidBST(root->right, rmin, rmax) || root->val >= rmin)
                return false;
            max = rmax;
        }
        return true;
    }
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int min = 0, max = 0;
        return isValidBST(root, min, max);
    }
};
