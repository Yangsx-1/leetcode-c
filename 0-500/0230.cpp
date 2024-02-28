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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int count = 0;
        int ans = 0;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* node = st.top();
                st.pop();
                ++count;
                if (count == k) {
                    ans = node->val;
                    return ans;
                }
                root = node->right;
            }
        }
        return ans;
    }
};