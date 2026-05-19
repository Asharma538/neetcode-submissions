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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL or head->next == NULL or k==1) return head;

        ListNode*prev_end   = NULL,
                *prev_start = NULL,
                *curr_start = NULL,
                *curr_end   = NULL,
                *p = NULL,
                *c = head,
                *n = head->next,
                *new_head = NULL;
        
        while(c != NULL){
            curr_end = c;
            p = NULL;
            for(int i=0; i<k; i++){
                if (c==NULL){
                    if (prev_end == NULL){
                        return reverseKGroup(p, i);
                    } else {
                        prev_end->next = reverseKGroup(p, i);
                        return new_head;
                    }
                }

                n = c->next;

                c->next = p;

                p = c;
                c = n;
            }
            curr_start=p;

            if (prev_end!=NULL) 
                prev_end->next = curr_start;
            else 
                new_head = curr_start;

            prev_start = curr_start;
            prev_end = curr_end;
        }

        return new_head;
    }
};
