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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        int tot = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            tot++; ptr=ptr->next;
        }
        n = tot - n;
        if (n==0) return head->next;

        ListNode* curr = head, *prev = NULL;

        while(n--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        return head;
    }
};
