class StockSpanner {
public:
   stack<pair<int,int>>st;
   int count;
    StockSpanner() {
    count =-1;
    }   
    
    int next(int price) {
        count++; // it is the price index or the day of the price
        int ans =0;
        while(!st.empty() && st.top().second <= price)st.pop();

        ans = st.empty() ? count+1 : count - st.top().first;

        st.push({count, price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */