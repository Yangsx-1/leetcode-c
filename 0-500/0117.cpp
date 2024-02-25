// finished in 2024.2.25
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void handle(Node* &last, Node* &p, Node* &nextstart) {
        if (last) {
            last->next = p;
        }
        if (!nextstart) {
            nextstart = p;
        }
        last = p;
    }
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* start = root;
        while (start) {
            Node* last = nullptr, *nextstart = nullptr;
            for (Node* p = start; p != nullptr; p = p->next) {
                if (p->left) {
                    handle(last, p->left, nextstart);
                }
                if (p->right) {
                    handle(last, p->right, nextstart);
                }
            }
            start = nextstart;
        }
        return root;
    }
};