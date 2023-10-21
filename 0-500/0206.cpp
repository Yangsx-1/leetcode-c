/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode* node = head->next;
    if(node == NULL) return head;
    struct ListNode* node2 = node->next;
    head->next = NULL;
    node->next = head;
    while(node2 != NULL){
        head = node;
        node = node2;
        node2 = node2->next;
        node->next = head;
    }
    return node;
}

// 递归做法
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
    ListNode* new_head;
    ListNode* recursive_reverse(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* next = head->next;
        if (next == nullptr) {
            new_head = head;
            return nullptr;
        }
        recursive_reverse(next);
        next->next = head;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* tail = recursive_reverse(head);
        if (tail != nullptr) tail->next = nullptr;
        return new_head;
    }
};