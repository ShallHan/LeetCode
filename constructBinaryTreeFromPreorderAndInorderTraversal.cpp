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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int a1, int a2, int a3, int a4)
    {
        if(a1 >= a2) return 0;
        TreeNode *root = new TreeNode(preorder[a1]);
        int middle = 0;
        for(; middle < a4 - a3; ++middle)
            if(preorder[a1] == inorder[a3 + middle])
                break;
        root->left = buildTree(preorder, inorder, a1 + 1, a1 + middle + 1, a3, a3 + middle);
        root->right = buildTree(preorder, inorder, a1 + middle + 1, a2, a3 + middle + 1, a4);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0) return 0;
        return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
