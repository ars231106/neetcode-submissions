class LRUCache {
public:
    class Node{
    public:
          int key, value;
          Node* prev;
          Node* next;

          Node(int k, int v){
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
          }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* left = new Node(0,0);
    Node* right = new Node(0,0);

    LRUCache(int capacity) {
        cap = capacity;

        left = new Node(0,0);
        right = new Node(0,0);

        left -> next = right;
        right -> prev = left;
    }

    void remove(Node* node){
        Node* prev = node -> prev;
        Node* next = node -> next;

        prev -> next = next;
        next -> prev = prev; 
    }

    void insert(Node* node){
        Node* prev = right -> prev;
        Node* next = right;

        prev -> next = node;
        node -> prev = prev;

        node -> next = next;
        next -> prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        remove(mp[key]);
        insert(mp[key]);

        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
            delete mp[key];
            mp.erase(key);   
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);

        if(mp.size() > cap){
            Node* lru = left -> next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */