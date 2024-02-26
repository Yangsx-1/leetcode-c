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
private:
    vector<int> ans;
    void dfs(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (depth == ans.size()) {
            ans.emplace_back(root->val);
        }
        depth++;
        dfs(root->right, depth);
        dfs(root->left, depth);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};