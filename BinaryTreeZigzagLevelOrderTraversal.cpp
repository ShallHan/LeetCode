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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res;
        if(root == 0) return res;
        vector<int> vec;
        deque<TreeNode *> deq;
        deq.push_back(root);
        bool order = true;
        while(!deq.empty())
        {
            deque<TreeNode *> deq_tmp;
            if(order)
            {
                while(!deq.empty())
                {
                    TreeNode *p = deq.front();
                    deq.pop_front();
                    vec.push_back(p->val);
                    if(p->left)
                        deq_tmp.push_back(p->left);
                    if(p->right)
                        deq_tmp.push_back(p->right);
                }
            }
            else
            {
                while(!deq.empty())
                {
                    TreeNode *p = deq.back();
                    deq.pop_back();
                    vec.push_back(p->val);
                    if(p->right)
                        deq_tmp.push_front(p->right);
                    if(p->left)
                        deq_tmp.push_front(p->left);
                }
            }
            order = !order;
            res.push_back(vec);
            vec.clear();
            deq = deq_tmp;
        }
    }
};
