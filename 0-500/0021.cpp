/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val = 0;
    tmp->next = NULL;
    struct ListNode* newhead = tmp;
    while(list1 != NULL && list2 != NULL){
        if(list1->val >= list2->val){
            tmp->next = list2;
            list2 = list2->next;
            tmp = tmp->next;
        }
        else{
            tmp->next = list1;
            list1 = list1->next;
            tmp = tmp->next;
        }
    }
    if(list1 != NULL){
        tmp->next = list1;
    }
    if(list2 != NULL){
        tmp->next = list2;
    }
    return newhead->next;
}
