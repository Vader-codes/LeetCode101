class StockSpanner {
    vector<int>ans;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int n= ans.size();

        // let's check if today's price is smaller that yesterday's price
        int day = 1;
        for(int i=n-2; i>=0; i--){
            if(ans[i] <= price)day++;

            else break;
        }
        return day;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */