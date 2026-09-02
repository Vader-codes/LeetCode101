class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sorting on the basis of pickup time
        sort(trips.begin(), trips.end() , [](vector<int>&a , vector<int>&b){
            return a[1] < b[1];
        });
        typedef pair<int,int>p;
        // make a min heap
        priority_queue< p, vector<p>, greater<p>>pq;
        int n = trips.size();
        int cap =0;
        for(int i=0; i<n; i++){

           // did we drop passengers before 
           while(!pq.empty() && pq.top().first <= trips[i][1]){
              cap-=pq.top().second;
              pq.pop();
           }
             cap += trips[i][0];
             if(cap > capacity )return false;
             // push curr into the heap
             pq.push({trips[i][2], trips[i][0]});

            
        }
        return true;
        
    }
};