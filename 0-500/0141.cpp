//套圈法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

// finished in 2023.11.9
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* quick = head;
        ListNode* slow = head;
        while (quick != nullptr) {
            for (int i = 0; i < 2; ++i) {
                if (quick->next != nullptr) quick = quick->next;
                else return false;
            }
            if (slow->next != nullptr) slow = slow->next;
            else return false;
            if (quick == slow) return true;
        }
        return false;
    }
};