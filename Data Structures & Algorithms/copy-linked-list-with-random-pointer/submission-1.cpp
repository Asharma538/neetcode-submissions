/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        map<Node*,Node*> mp;
        Node* ptr = head;


        Node* newHead = new Node(head->val);
        Node* ptr2 = newHead;

        mp[ptr] = ptr2;

        while(ptr->next!=NULL){
            ptr2->next = new Node(ptr->next->val);
            ptr2 = ptr2->next; ptr = ptr->next;
            mp[ptr] = ptr2;
        }

        ptr = head;
        ptr2 = newHead;

        while(ptr!=NULL){
            ptr2->random = mp[ptr->random];
            ptr = ptr->next; ptr2 = ptr2->next;
        }

        return newHead;
    }
};



