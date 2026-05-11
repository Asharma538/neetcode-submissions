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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr){
            n++;
            ptr=ptr->next;
        }
        
        ListNode* prev, *curr, *nxt;
        prev = NULL;
        curr = head;
        for(int i = 0; i<=(n/2); i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;

        prev = NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        curr = prev;

        ListNode* tmp = head;
        while(curr!=NULL and tmp!=NULL){
            nxt = tmp->next;
            prev = curr;
            curr = curr->next;

            prev->next = tmp->next;
            tmp->next = prev;

            tmp = nxt;
        }
    }
};



