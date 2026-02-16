// Last updated: 16/02/2026, 11:58:05
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfsTree(TreeNode* root){
        if (root==NULL) return 0;

        int l = dfsTree(root->left);
        if (l==-1) return -1;
        int r = dfsTree(root->right);
        if (r==-1) return -1;

        if (abs(r-l)>1) return -1;
        return max(r, l)+1;
    }
    bool isBalanced(TreeNode* root) {
        return dfsTree(root) != -1;
    }
};