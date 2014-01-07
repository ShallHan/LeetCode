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
    int maxPathSum(TreeNode *root, int &full_len, int &part_len)
    {
        if(root == 0) 
        {
            full_len = 0; 
            part_len = 0;
            return 0;
        }
        if(!root->left && !root->right)
        {
            full_len = root->val;
            part_len = root->val;
            return root->val;
        }
        int full_l = INT_MIN, full_r = INT_MIN, part_l = INT_MIN, part_r = INT_MIN;
        if(root->left && root->right)
        {
            maxPathSum(root->left, full_l, part_l);
            maxPathSum(root->right, full_r, part_r);
            part_len = max(root->val + max(part_l, part_r), root->val);
            full_len = part_l + part_r + root->val;
            if(full_l > full_len)
                full_len = full_l;
            if(full_r > full_len)
                full_len = full_r;
            if(part_len > full_len)
                full_len = part_len;
            return full_len;
        }
        if(root->left)
        {
            maxPathSum(root->left, full_l, part_l);
            part_len = max(root->val + part_l, root->val);
            full_len = max(part_len, full_l);
            return full_len;
        }
        else
        {
            maxPathSum(root->right, full_r, part_r);
            part_len = max(root->val + part_r, root->val);
            full_len = max(part_len, full_r);
            return full_len;
        }
        
    }
    int maxPathSum(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int a1 = 0, a2 = 0;
        return maxPathSum(root, a1, a2);
    }
};
