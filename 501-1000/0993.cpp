// finished in 2024.2.8
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int pos_x = -1, pos_y = -1;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                if (t == nullptr) continue;
                if (t->left) {
                    q.push(t->left);
                } else {
                    q.push(nullptr);
                }
                if (t->right) {
                    q.push(t->right);
                } else {
                    q.push(nullptr);
                }
                if (t->val == x) {
                    pos_x = i;
                } else if (t->val == y) {
                    pos_y = i;
                }
            }
            if (pos_x != -1 && pos_y != -1) {
                if (pos_x % 2 == 0 && pos_y == pos_x+1) {return false;}
                else if (pos_y % 2 == 0 && pos_x == pos_y+1) {return false;}
                else {return true;}
            }
        }
        return false;
    }
};