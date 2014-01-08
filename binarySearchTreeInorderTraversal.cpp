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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vec;
        if(root == 0)
            return vec;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while(p || !stk.empty())
        {
            while(p)
            {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            vec.push_back(p->val);
            p = p->right;
        }
        return vec;
    }
};
