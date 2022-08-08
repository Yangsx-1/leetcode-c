/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *big = (struct ListNode*)malloc(sizeof(struct ListNode));
    big->next = NULL;
    struct ListNode *small = (struct ListNode*)malloc(sizeof(struct ListNode));
    small->next = NULL;
    struct ListNode *newhead1 = small;
    struct ListNode *newhead2 = big;
    while(head != NULL){
        if(head->val < x){
            small->next = head;
            head = head->next;
            small = small->next;
        }else{
            big->next = head;
            head = head->next;
            big = big->next;
        }
    }
    big->next = NULL;
    small->next = newhead2->next;
    return newhead1->next;
}
