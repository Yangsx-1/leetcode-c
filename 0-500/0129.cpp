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
    int number = 0;
    int sum = 0;
public:
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        number = number * 10 + root->val;
        if (root->left) {
            dfs(root->left);
        }
        if (root->right) {
            dfs(root->right);
        }
        if (!root->left && !root->right) {
            sum += number;
        }
        number = (number - root->val) / 10;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};