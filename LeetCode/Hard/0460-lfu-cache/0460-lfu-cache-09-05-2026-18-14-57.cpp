class Node{
    public:
    int key, value, freq;
    Node* next;
    Node* prev;
    // constructor of our Node
    Node(int k, int v, int f){
        this->key = k;
        this->value = v;
        this->freq = f;

        next = prev = NULL;
    }
};
class List{
   public: 
   int size;
   Node* head;
   Node* tail;

   List(){
    head = new Node(-1, -1, -1);
    tail = new Node(-1, -1, -1);
    size =0;
    head->next = tail;
    tail->prev = head;

   }
   // what we can do in our dll 
   // we can add and delte a node
   void insert(Node* node){
    // we always add in front
      node->next = head->next;
      node->prev = head;
      head->next->prev = node;
      head->next = node;
      size++;

   }
   void remove(Node* node){
    // just change the pointers
      node->prev->next = node->next;
      node->next->prev = node->prev;
      size--;
   }
};

class LFUCache {
public:
//  we need to map each node to a key \
and each freq to a dll
 unordered_map<int,Node*>mp;
 unordered_map<int, List*>freqMap;
 int cap;
 int minFreq;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq=0;
    }
    // function to update the freq of a node 
    void update(Node* node){
        int f = node->freq;
        freqMap[f]->remove(node);

        if( f == minFreq && freqMap[f]->size ==0)minFreq++;

        node->freq++;
        f = node->freq;

        if(freqMap.find(f) == freqMap.end()){
                // we do not have it
                freqMap[f] = new List();
        }
        freqMap[f]->insert(node);
    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        int val = mp[key]->value;
        Node* node = mp[key];
        update(node);
        return val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            update(node);
           
        }else{
            // there could be two cases eiter full capacity or not
            if(mp.size() == cap){
                // need to delete the lru of lfu
                List* list = freqMap[minFreq];
                Node* temp = list->tail->prev;
                mp.erase(temp->key);
                list->remove(temp);
            }
            Node* node = new Node(key, value, 1);
            // since we created this node it is going to be our lfu
            minFreq = 1;
            if(freqMap.find(1) == freqMap.end()){
                freqMap[1] = new List();
            }
            freqMap[1]->insert(node);
            mp[key] = node;
            
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */