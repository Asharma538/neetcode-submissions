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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *a = l1, 
                 *b = l2;

        ListNode *l3   = NULL, 
                 *curr = NULL, 
                 *prev = NULL;
        
        while(a!=NULL and b!=NULL){
            curr = new ListNode((c + a->val + b->val)%10);
            c = (c + a->val + b->val)/10;

            if (l3 == NULL){
                l3 = curr;
                prev = curr;
            } else {
                prev->next = curr;
                prev = prev->next;
            }
            // cout<<a->val<<' '<<b->val<<'\n';
            a = a->next;
            b = b->next;
        }

        while(a!=NULL){
            curr = new ListNode((c + a->val)%10);
            c = (c + a->val)/10;

            if (l3 == NULL){
                l3 = curr;
                prev = curr;
            } else {
                prev->next = curr;
                prev = prev->next;
            }
            a = a->next;
        }

        while(b!=NULL){
            curr = new ListNode((c + b->val)%10);
            c = (c + b->val)/10;

            if (l3 == NULL){
                l3 = curr;
                prev = curr;
            } else {
                prev->next = curr;
                prev = prev->next;
            }
            b = b->next;
        }

        if (c){
            prev->next = new ListNode(c);
        }

        return l3;
    }
};
