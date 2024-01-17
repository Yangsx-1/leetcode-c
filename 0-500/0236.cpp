// finished in 2024.1.17
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
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool left_child = dfs(root->left, p, q);
        bool right_child = dfs(root->right, p, q);
        if((left_child && right_child) || ((root == p || root == q) && (left_child || right_child))) {
            ans = root;
        }
        return left_child || right_child || (root == p || root == q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};