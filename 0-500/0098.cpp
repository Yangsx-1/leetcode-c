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
    bool check(TreeNode* root, int val, bool isright) {
        if (root == nullptr) return true;
        if (isright) {
            if (root->val <= val) return false;
            if (!check(root->left, val, isright)) return false;
            if (!check(root->right, val, isright)) return false;
        } else {
            if (root->val >= val) return false;
            if (!check(root->left, val, isright)) return false;
            if (!check(root->right, val, isright)) return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left != nullptr) {
            if (!check(root->left, root->val, false)) return false;
        }
        if (root->right != nullptr) {
            if (!check(root->right, root->val, true)) return false;
        }
        bool isleft = isValidBST(root->left);
        bool isright = isValidBST(root->right);
        if (isleft && isright) return true;
        else return false;
    }
};