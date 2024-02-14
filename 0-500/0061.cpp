// finished in 2024.2.13
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode* node = head;
        while (node->next) {
            ++len;
            node = node->next;
        }
        node->next = head;
        while (k >= len) k -= len;
        int step = len - k;
        while (step > 0) {
            node = node->next;
            --step;
        }
        ListNode* newhead = node->next;
        node->next = nullptr;
        return newhead;
    }
};