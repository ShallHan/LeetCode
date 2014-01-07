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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int a1, int a2, int a3, int a4)
    {
        if(a1 >= a2) return 0;
        TreeNode *p = new TreeNode(postorder[a4 - 1]);
        int middle = 0;
        for(; middle < a2 - a1; ++middle)
            if(inorder[middle + a1] == postorder[a4 - 1])
                break;
        p->left = buildTree(inorder, postorder, a1, a1 + middle, a3, a3 + middle);
        p->right = buildTree(inorder, postorder, a1 + middle + 1, a2, a3 + middle, a4 - 1);
        return p;
        
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(inorder.size() == 0) return 0;
        return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
