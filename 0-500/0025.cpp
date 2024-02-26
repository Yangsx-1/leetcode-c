// finished in 2024.2.26
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
    pair<ListNode* , ListNode*> reverseonelist(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* cur = head;
        while (prev != tail) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* pre = dummynode;
        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return dummynode->next;
                }
            }
            ListNode* next = tail->next;
            auto result = reverseonelist(head, tail);
            head = result.first;
            tail = result.second;
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = next;
        }
        return dummynode->next;
    }
};