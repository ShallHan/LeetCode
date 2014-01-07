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
    bool isBalanced(TreeNode *root, int &depth)
    {
        if(root == 0) 
        {
            depth = 0;
            return true;
        }
        int left = 0, right = 0;
        if(isBalanced(root->left, left) && isBalanced(root->right, right))
        {
            if(left - right >= -1 && left - right <= 1) 
            {
                depth = max(left, right) + 1;
                return true;
            }
        }
        return false;
    }
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int depth = 0;
        return isBalanced(root, depth);
    }
};
