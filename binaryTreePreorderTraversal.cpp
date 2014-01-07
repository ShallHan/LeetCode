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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        if(root == 0)
            return vec;
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *p = stk.top();
            stk.pop();
            vec.push_back(p->val);
            if(p->right)
                stk.push(p->right);
            if(p->left)
                stk.push(p->left);
        }
        return vec;
    }
};
