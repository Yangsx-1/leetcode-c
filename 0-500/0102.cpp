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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> vec;
        if (root == nullptr) return vec;
        q.push(root);
        vector<int> tmp;
        while (q.size() > 0) {
            tmp.clear();
            int count = q.size();
            while (count > 0) {
                count--;
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            vec.push_back(tmp);
        }
        return vec;
    }
};