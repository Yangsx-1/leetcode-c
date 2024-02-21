// finished in 2024.2.21
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
    vector<int> postorder;
    unordered_map<int, int> mp;
    TreeNode* recur(int root, int left, int right) {
        if (left > right) return nullptr;
        TreeNode* node = new TreeNode(postorder[root]);
        int i = mp[postorder[root]];
        node->left = recur(root-right+i-1, left, i-1);
        node->right = recur(root-1, i+1, right);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return recur(postorder.size()-1, 0, inorder.size()-1);
    }
};