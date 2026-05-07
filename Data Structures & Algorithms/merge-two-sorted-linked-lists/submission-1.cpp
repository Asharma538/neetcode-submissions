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
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        if (p1 == NULL) return list2;
        if (p2 == NULL) return list1;

        ListNode* list3 = new ListNode();
        ListNode* p = list3;
        while(p1!=NULL and p2!=NULL){
            if (p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2 = p2->next;
            }
            if (p1 != NULL) cout<<p1->val<<' '; else cout<<"NULL ";
            if (p2 != NULL) cout<<p2->val<<' '; else cout<<"NULL ";
            cout<<'\n';
            p = p->next;
        }
        while (p1!=NULL){
            cout<<p1->val<<'\n';
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        while (p2!=NULL){
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        return list3->next;
    }
};
