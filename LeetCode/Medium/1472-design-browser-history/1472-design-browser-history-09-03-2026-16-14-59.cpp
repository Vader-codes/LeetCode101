// we need a double linked list
class Node{
    public:
    string page;
    Node* next;
    Node* back;

    Node( string url ){
        this->page = url;
        this->next = nullptr;
        this->back = nullptr;
    }

};
class BrowserHistory {
public:
  Node* currPage;
    BrowserHistory(string homepage) {
        currPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currPage->next = newNode;
        newNode->back = currPage;
        currPage = newNode;
     
    }
    
    string back(int steps) {
        while(steps){
            if(currPage->back){
                currPage = currPage->back;
            }else break;
                steps--;
        }
        return currPage->page;
    }
    
    string forward(int steps) {
        while(steps){
            if(currPage->next){
                currPage = currPage->next;
            }
                else break;
                steps--;
        }
        return currPage->page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */