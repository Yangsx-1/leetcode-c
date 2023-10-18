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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* last = head;
        ListNode* prior;
        int count = 0;
        while (last != nullptr) {
            if (count < n) {
                last = last->next;
                count++;
            }
            else {
                prior = first;
                first = first->next;
                last = last->next;
            }
        }
        if (first == head) return first->next;
        else {
            prior->next = first->next;
            return head;
        }
    }
};