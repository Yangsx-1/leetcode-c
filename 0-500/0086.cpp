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

// finished in 2024.2.23
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smalldummy = new ListNode(0);
        ListNode* largedummy = new ListNode(0);
        ListNode* p = smalldummy, *q = largedummy;
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = nullptr;
            if (tmp->val < x) {
                p->next = tmp;
                p = p->next;
            } else {
                q->next = tmp;
                q = q->next;
            }
        }
        p->next = largedummy->next;
        return smalldummy->next;
    }
};