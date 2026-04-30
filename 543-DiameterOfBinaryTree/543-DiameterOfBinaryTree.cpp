// Last updated: 30/04/2026, 19:58:09
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
    int diameter;
    int longestPath(TreeNode* root){
        if (!root) return -1;
        int right = longestPath(root->right);
        int left = longestPath(root->left);
        diameter = max(diameter, right+left+2);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }

};