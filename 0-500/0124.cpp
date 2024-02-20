// finished in 2024.2.20
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
    int maxsum = INT_MIN;
public:
    int maxgain(TreeNode* root) {
        if (!root) return 0;
        int left = max(maxgain(root->left), 0);
        int right = max(maxgain(root->right), 0);
        int curr = root->val + left + right;
        maxsum = max(maxsum, curr);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return maxsum;
    }
};