// finished in 2023.11.28

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
    void deep_traverse(TreeNode* root, int depth) {
        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > max_depth) max_depth = depth;
        }
        if (root->left != nullptr) deep_traverse(root->left, depth);
        if (root->right != nullptr) deep_traverse(root->right, depth);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        deep_traverse(root, 0);
        return max_depth;
    }
private:
    int max_depth = 0;
};