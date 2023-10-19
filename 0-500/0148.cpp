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
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        ListNode* first = head;
        while (first != nullptr) {
            vals.push_back(first->val);
            first = first->next;
        }
        sort(vals.begin(), vals.end());
        int count = 0;
        for (first = head; first != nullptr; first = first->next) {
            first->val = vals[count];
            count++;
        }
        return head;
    }
};