// finished in 2024.2.26
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
    int s = 0;
    void dfs(TreeNode* root, int low, int high) {
        if (!root) return;
        int cur = root->val;
        if (cur >= low && cur <= high) {
            s += cur;
            dfs(root->left, low, high);
            dfs(root->right, low, high);
        } else if (cur < low) {
            dfs(root->right, low, high);
        } else {
            dfs(root->left, low, high);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return s;
    }
};