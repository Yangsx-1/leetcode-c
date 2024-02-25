// finished in 2024.2.25
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* node;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        if ((left && right) || ((root == p || root == q) && (left || right))) {
            node = root;
        }
        return left || right || root == p || root == q;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return node;
    }
};