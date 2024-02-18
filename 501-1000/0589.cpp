// finished in 2024.2.18
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void dfs(Node* root) {
        if (!root) return;
        ans.emplace_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            dfs(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};