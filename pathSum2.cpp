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
    void pathSum(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> path)
    {
        if(root == 0) return;
        if(!root->left && !root->right)
        {
            if(sum != root->val)
                return;
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        pathSum(root->left, sum - root->val, res, path);
        pathSum(root->right, sum - root->val, res, path);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res;
        if(root == 0) return res;
        vector<int> path;
        pathSum(root, sum, res, path);
    }
};
