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
    TreeNode *sortedArrayToBST(vector<int> &num, int i, int j)
    {
        if(i >= j) return 0;
        int middle = i + (j - i) / 2;
        TreeNode *left = sortedArrayToBST(num, i, middle);
        TreeNode *right = sortedArrayToBST(num, middle+1, j);
        TreeNode *p = new TreeNode(num[middle]);
        p->left = left;
        p->right = right;
        return p;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(num.size() == 0) return 0;
        return sortedArrayToBST(num, 0, num.size());
    }
};
