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
    bool hasCycle(ListNode* head) {
        ListNode* f = head, *s = head;        
        while(f!=NULL and f->next!=NULL){
            f = f->next->next;
            s = s->next;

            if (s == f) return true;
        }

        return false;
    }
};
