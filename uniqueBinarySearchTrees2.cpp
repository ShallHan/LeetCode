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
    vector<TreeNode *> generateTrees(int n) 
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<TreeNode *> vec;
        generateTrees(vec, 1, n);
        return vec;
    }
    void generateTrees(vector<TreeNode*> &vec, int beg, int end)
    {
        if(end < beg)
            vec.push_back(0);
        for(int i = beg; i <= end; ++i)
        {
              vector<TreeNode*> left, right;
              generateTrees(left, beg, i-1);
              generateTrees(right, i+1, end);
              for(int m = 0; m < left.size(); ++m)
              {
                  for(int n = 0; n < right.size(); ++n)
                  {
                      TreeNode *p = new TreeNode(i);
                      p->left = left[m];
                      p->right = right[n];
                      vec.push_back(p);
                  }
              }
        }
    }
};
