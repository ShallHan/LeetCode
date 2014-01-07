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
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == 0) return 0;
        int sum = 0;
        deque<pair<TreeNode*, int> > deq;
        deq.push_back(make_pair(root, 0));
        while(!deq.empty())
        {
            pair<TreeNode *, int> tmp_pair = deq.front();
            deq.pop_front();
            TreeNode *p = tmp_pair.first;
            int val = tmp_pair.second;
            if(!p->left && !p->right)  
                sum += val * 10 + p->val;
            else
            {
                if(p->left)
                    deq.push_back(make_pair(p->left, val*10 + p->val));
                if(p->right)
                    deq.push_back(make_pair(p->right, val*10 + p->val));
            }
        }
        return sum;
    }
};
