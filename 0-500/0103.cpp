// finished in 2024.2.13
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        if (!root) return ans;
        dq.push_back(root);
        bool ltor = true;
        while (!dq.empty()) {
            int n = dq.size();
            ans.emplace_back();
            for (int i = 0; i < n; ++i) {
                TreeNode* tmp;
                if (ltor) {
                    tmp = dq.front();
                    ans.back().emplace_back(tmp->val);
                    dq.pop_front();
                    if (tmp->left) dq.push_back(tmp->left);
                    if (tmp->right) dq.push_back(tmp->right);
                } else {
                    tmp = dq.back();
                    ans.back().emplace_back(tmp->val);
                    dq.pop_back();
                    if (tmp->right) dq.push_front(tmp->right);
                    if (tmp->left) dq.push_front(tmp->left);
                }
            }
            ltor = !ltor;
        }
        return ans;
    }
};