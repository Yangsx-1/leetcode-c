// finished in 2024.2.7
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> deq;
        auto s = root->val;
        deq.emplace_back(root, root->val);
        while (!deq.empty()) {
            deque<pair<TreeNode*, int>> deq2;
            auto s2 = 0;
            while (!deq.empty()) {
                deq.front().first->val = s - deq.front().second;
                auto t = deq.front().first;
                if (t->left && t->right) {
                    auto tmp = t->left->val + t->right->val;
                    deq2.emplace_back(t->left, tmp);
                    deq2.emplace_back(t->right, tmp);
                    s2 += tmp;
                } else if (t->left) {
                    auto tmp = t->left->val;
                    deq2.emplace_back(t->left, tmp);
                    s2 += tmp;
                } else if (t->right) {
                    auto tmp = t->right->val;
                    deq2.emplace_back(t->right, tmp);
                    s2 += tmp;
                }
                deq.pop_front();
            }
            s = s2;
            deq = move(deq2);
        }
        return root;
    }
};

// dfs
#define SIZE (100000)
long long sum[SIZE];

void dfsLevel(struct TreeNode* root, int depth) {
    if (root == NULL) {
        return;
    }
    
    sum[depth++] += root->val;
    dfsLevel(root->left, depth);
    dfsLevel(root->right, depth);
}

void dfsUpdate(struct TreeNode* root, int depth) {
    if (root == NULL) {
        return;
    }

    depth++;
    if (root->left && root->right) {
        int left = root->left->val;
        int right = root->right->val;
        root->left->val = sum[depth] - left - right;
        root->right->val = sum[depth] - left - right;
    } else if (root->left) {
        root->left->val = sum[depth] - root->left->val;
    } else if (root->right) {
        root->right->val = sum[depth] - root->right->val;
    }

    dfsUpdate(root->left, depth);
    dfsUpdate(root->right, depth);
}

struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    memset(&sum, 0, SIZE * sizeof(long long));

    dfsLevel(root, 0);
    root->val = 0;
    dfsUpdate(root, 0);
    return root;
}