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
    bool isPalindrome(ListNode* head) {
        int num = 0;
        ListNode* start = head;
        while (start != nullptr) {
            num++;
            start = start->next;
        }
        stack<int> s;
        start = head;
        int mid = num % 2 == 0 ? num / 2 : num / 2 + 1;
        int count = 0;
        while (start != nullptr) {
            count++;
            if (count <= mid) {
                if(count != mid || num % 2 == 0) s.push(start->val);
            } else {
                if (start->val != s.top()) return false;
                s.pop();
            }
            start = start->next;
        }
        return true;
    }
};