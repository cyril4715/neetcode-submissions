
class LRUCache {
private:
struct Node {
        int key; 
        int value;
        Node* next; 
        Node* prev;
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };
 int cap ; Node* left ;Node* right;
    unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity) {
        cap = capacity;   
        left = new Node(0, 0) ; right = new Node(0, 0);
        left->next = right ; right->prev = left;
    }
    void remove(Node* node){            // can either remove from left->next or any where in the middle . removes the least recently used in list (oldest item)//whenever put/get used move remvove item and place it at right->prev (mru)
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insert(Node* node){ // alwasys insert at right->prev the MRU after a get/put
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = right;
        right->prev = node;
    }
    
    int get(int key) {
        if(cache.contains(key)){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)){
            remove(cache[key]);
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if (cache.size() > cap){ // if cap exeeds always evict at left->next the LRU (oldest item)
        Node* lru = left->next;
        remove(lru);
        cache.erase(lru->key);
        delete lru; 
        }  
    }
};