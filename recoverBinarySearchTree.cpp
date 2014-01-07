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
    void traversal(TreeNode *root)
    {
        if(root->left) traversal(root->left);
        if(prev)
        {
            if(root->val < prev->val)
            {
                vec.push_back(prev);
                vec.push_back(root);
            }
        }
        prev = root;
        if(root->right) traversal(root->right);
    }
    TreeNode *prev;
    vector<TreeNode *> vec;
    void recoverTree(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == 0) return;
        prev = 0;
        vec.clear();
        traversal(root);
        if(vec.size() < 2 || vec.size() > 4) return;
        TreeNode *p1 = vec[0];
        TreeNode *p2 = vec[vec.size() - 1];
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
};
