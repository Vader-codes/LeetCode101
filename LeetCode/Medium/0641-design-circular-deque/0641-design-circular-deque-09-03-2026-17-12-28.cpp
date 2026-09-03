class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyCircularDeque {
public:
    Node* front;
    Node* rear;
    int size;
    int capacity;
    MyCircularDeque(int k) {
        size = 0;
        front = nullptr;
        rear = nullptr;
        capacity = k;
    }

    bool insertFront(int value) {
        // can only add if we have spacce
        if (isFull()) {
            return false;
        }
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        // can only insert if ew have space left
        if(isFull())return false;

        Node* newNode = new Node(value);
        if(isEmpty()){
            front = rear = newNode;

        }else{
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty())return false;
        Node* temp = front;
        if(size == 1){
            front = rear = NULL;
        }
        else{
            front = front->next;
            front->prev = NULL;
            delete temp;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if(isEmpty())return false;
        Node* del = rear;

        if(size == 1){
            front=rear=nullptr;
        }
        else{
            rear = rear->prev;
            rear->next = NULL;
            delete del;
        }
        size--;
        return true;
    }

    int getFront() {
        if(isEmpty())return -1;

        return front->val;
    }

    int getRear() {
        if(isEmpty())return -1;

        return rear->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */