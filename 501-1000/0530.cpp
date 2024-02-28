// finished in 2024.2.28
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
private:
    int ans = INT_MAX;
    int get_max(TreeNode* root) {
        int m = root->val;
        while (root->right) {
            root = root->right;
            m = root->val;
        }
        return m;
    }
    int get_min(TreeNode* root) {
        int m = root->val;
        while (root->left) {
            root = root->left;
            m = root->val;
        }
        return m;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            ans = min(ans, abs(root->val - get_max(root->left)));
            dfs(root->left);
        }
        if (root->right) {
            ans = min(ans, abs(root->val - get_min(root->right)));
            dfs(root->right);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};