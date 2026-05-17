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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *p1 = l1, *p2 = l2;
        ListNode* p3 = NULL, *head = NULL;

        

        while(p1!=NULL and p2!=NULL){
            if (p1->val < p2->val){
                if (p3==NULL){
                    head = p1;
                    p3 = p1;
                }
                else{
                    p3->next = p1;
                    p3 = p3->next;
                }

                p1 = p1->next;
            } else {
                if (p3==NULL){
                    head = p2;
                    p3 = p2;
                }
                else{
                    p3->next = p2;
                    p3 = p3->next;
                }

                p2 = p2->next;
            }
        }

        while(p1!=NULL){
            if (p3==NULL){
                head = p1;
                p3 = p1;
            }
            else{
                p3->next = p1;
                p3 = p3->next;
            }

            p1 = p1->next;
        }

        while(p2!=NULL){
            if (p3==NULL){
                head = p2;
                p3 = p2;
            }
            else{
                p3->next = p2;
                p3 = p3->next;
            }

            p2 = p2->next;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];

        for(int i = 1 ; i < lists.size() ; i++){
            lists[i] = mergeTwoLists(lists[i-1], lists[i]);
        }

        return lists[lists.size() - 1];
    }
};




