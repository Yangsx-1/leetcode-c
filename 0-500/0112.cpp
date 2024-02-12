// finished in 2024.2.12
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
    int testtarget = 0;
    bool haspath = false;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        testtarget += root->val;
        if (root->left) {
            hasPathSum(root->left, targetSum);
        }
        if (root->right) {
            hasPathSum(root->right, targetSum);
        }
        if (!root->left && !root->right && testtarget == targetSum) haspath = true;
        testtarget -= root->val;
        return haspath;
    }
};