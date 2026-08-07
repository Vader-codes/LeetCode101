class MedianFinder {
public:
 // max-heap 
 // left half of sorted array
 priority_queue<int>left_max;
 // now min-heap for sorted right half
 priority_queue<int, vector<int>, greater<int>>right_min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // step 1 we always add to left_max
        left_max.push(num);

        // step2 : balance ordere move largest form the left_max to right_min
        if(!right_min.empty() && left_max.top() > right_min.top()){
            // we have something in  left that should be in right
            right_min.push(left_max.top());
            left_max.pop();
        }
        // we have to maintain the left max
        if(left_max.size() > right_min.size()+1){
            right_min.push(left_max.top());
            left_max.pop();
        }
        else if(right_min.size() > left_max.size()){
            left_max.push(right_min.top());
            right_min.pop();
        }

    }
    
    double findMedian() {
        if(left_max.size() == right_min.size()){
            return(left_max.top() + right_min.top())/2.0;
        }
        return left_max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */