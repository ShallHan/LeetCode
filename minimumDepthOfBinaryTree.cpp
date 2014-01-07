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
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == 0) return 0;
        if(!root->left && !root->right) return 1;
        if(root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        if(root->left)
            return minDepth(root->left) + 1;
        else
            return minDepth(root->right) + 1;
    }
};
