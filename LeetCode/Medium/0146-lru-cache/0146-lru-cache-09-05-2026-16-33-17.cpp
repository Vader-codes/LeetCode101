class Node{
    public:
    int key, value;
    Node* next;
    Node* prev;

    Node(int k ,int v){
        this->key = k;
        this->value =v;
        next = prev = NULL;
    }

};
class LRUCache {
public:
unordered_map<int, Node*>mp;
 Node* head, *tail;
 int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev= head;
    }
    // add a new node in to the dll
    void insert(Node* node){
        // we need to insert if after the head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

    }
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        // now if key exists , and we are accessing it , this becomes our recenlty accesed should go to front
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value; // address is same as before no need to change the map
    }
    
    void put(int key, int value) {
        // if key already exists 
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
        }
        else{
            // if the capacity is full remove the lru
            if(mp.size() == cap){
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete(lru);

            }
            // create a new node
            Node* node = new Node(key, value);
            mp[key] = node;
            insert(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */