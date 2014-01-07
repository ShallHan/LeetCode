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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        if(root == 0)
            return vec;
        stack< pair<TreeNode *, bool> > stk;
        stk.push(make_pair(root, false));
        while(!stk.empty()) {
            pair<TreeNode*, bool> p = stk.top();
            if(p.second == false)
            {
                stk.pop();
                p.second = true;
                stk.push(p);
                if(p.first->right)
                    stk.push(make_pair(p.first->right, false));
                if(p.first->left)
                    stk.push(make_pair(p.first->left, false));
            }
            else
            {
                vec.push_back(p.first->val);
                stk.pop();
            }
        }
        return vec;
    }
};
