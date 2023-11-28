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
    void left_traverse(TreeNode* root, vector<int>& vec){
        if (root == nullptr) {
            vec.push_back(101);
            return;
        }
        vec.push_back(root->val);
        left_traverse(root->left, vec);
        left_traverse(root->right, vec);
    }

    void right_traverse(TreeNode* root, vector<int>& vec){
        if (root == nullptr) {
            vec.push_back(101);
            return;
        }
        vec.push_back(root->val);
        right_traverse(root->right, vec);
        right_traverse(root->left, vec);
    }

    bool isSymmetric(TreeNode* root) {
        vector<int> left;
        vector<int> right;
        left_traverse(root, left);
        right_traverse(root, right);
        for (int i = 0; i < left.size(); ++i){
            if (left[i] != right[i]) return false;
        }
        return true;
    }
};