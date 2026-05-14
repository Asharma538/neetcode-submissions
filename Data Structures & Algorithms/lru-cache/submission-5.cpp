class Node{
public:
    int key , val;
    Node* prev, *next;

    Node(int _key = -1, int _val = -1){
        key = _key;
        val = _val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    Node* start = NULL, *end = NULL;
    map<int, Node*> h;
    int cap = -1;

    void insert(int key, int value){
        Node* tmp = new Node(key, value);
        if (start == NULL){
            start = end = tmp;
        } else {
            tmp->next = start;
            start->prev = tmp;
            start = tmp;
        }

        h[key] = start;
        
        if (h.size() > cap) remove(end->key);
    }

    void remove(int key){
        Node* tmp = h[key];
        if (tmp == start and tmp == end){
            start = end = NULL;
        } else if (tmp == start){
            start = start->next;
            start->prev = NULL;
        } else if (tmp == end){
            end = end->prev;
            end->next = NULL;
        } else {
            Node* prv = tmp->prev;
            Node* nxt = tmp->next;
            prv->next = nxt;
            nxt->prev = prv;
        }
        
        h.erase(key); 
        delete tmp;
    }

public:
    LRUCache(int _capacity) {
        cap = _capacity;
    }
    
    int get(int key) {
        if (h.find(key) == h.end()) return -1;
        
        int val = h[key]->val;
        remove(key);
        insert(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (h.find(key) != h.end()){
            remove(key);
        }
        insert(key, value);
    }
};