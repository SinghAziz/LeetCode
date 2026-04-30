// Last updated: 30/04/2026, 19:57:42
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
    int ans=0;
    void helper(TreeNode* root, int node){
        if (!root) return;
        if (root->val>=node){
            ans++;
            helper(root->right, max(node, root->val));
            helper(root->left, max(node, root->val));
        }
        else{
            helper(root->right, node);
            helper(root->left, node);
        }
    }
    int goodNodes(TreeNode* root) {
        if (!root) return ans;
        helper(root, root->val);
        return ans;
    }
};