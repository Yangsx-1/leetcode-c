// finished in 2024.2.5
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (true) {
            int min_id = -1;
            for (int i = 0; i < k; ++i) {
                if (lists[i] == nullptr) {
                    continue;
                } else {
                    if (min_id == -1 || lists[i]->val < lists[min_id]->val) {
                        min_id = i;
                    }
                }
            }
            if (min_id == -1) break;
            curr->next = lists[min_id];
            curr = curr->next;
            lists[min_id] = lists[min_id]->next;
        }
        return head->next;
    }
};