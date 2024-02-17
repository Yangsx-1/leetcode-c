// finished in 2024.2.17
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* first = head, * second = head->next;
        ListNode* dummynode = new ListNode(0);
        ListNode* cur = dummynode;
        while (first && second) {
            cur->next = second;
            first->next = second->next;
            if (second->next) second = second->next->next;
            else second = nullptr;
            cur = cur->next;
            cur->next = first;
            first = first->next;
            cur = cur->next;
        }
        return dummynode->next;
    }
};