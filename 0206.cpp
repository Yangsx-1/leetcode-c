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
