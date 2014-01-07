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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res;
        if(root == 0) return res;
        vector<int> vec;
        deque<TreeNode *> deq;
        deq.push_back(root);
        deq.push_back(0);
        while(!deq.empty())
        {
            TreeNode *p = deq.front();
            deq.pop_front();
            if(p == 0)
            {
                res.push_back(vec);
                vec.clear();
                if(!deq.empty())
                    deq.push_back(0);
                continue;
            }
            vec.push_back(p->val);
            if(p->left)
                deq.push_back(p->left);
            if(p->right)
                deq.push_back(p->right);
        }
        return res;
    }
};
