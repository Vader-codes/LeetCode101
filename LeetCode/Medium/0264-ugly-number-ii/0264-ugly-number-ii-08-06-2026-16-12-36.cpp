class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        unordered_set<long long>st;

        pq.push(1);
        st.insert(1);
        long long num = 0;
        int i=0; 
        while(i < n){
             num = pq.top(); pq.pop();

            if(st.find(num*2) == st.end())pq.push(num*2);
            if(st.find(num*3) == st.end())pq.push(num*3);
            if(st.find(num*5) == st.end())pq.push(num*5);

            st.insert(num*2);
            st.insert(num*3);
            st.insert(num*5);
            i++;
        }
        return (int)num;
        
    }
};