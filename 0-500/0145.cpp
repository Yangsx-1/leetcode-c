// finished in 2024.2.11
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                ans.emplace_back(root->val);
                st.push(root);
                root = root->right;
            } else {
                root = st.top();
                st.pop();
                root = root->left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};