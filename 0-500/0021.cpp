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

// finished in 2023.10.23
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prehead = new ListNode();
        ListNode* prev = prehead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return prehead->next;
    }
};