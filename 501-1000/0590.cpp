// finished in 2024.2.19
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
        for (int i = 0; i < root->children.size(); ++i) {
            dfs(root->children[i]);
        }
        ans.emplace_back(root->val);
    }
    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
};