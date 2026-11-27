class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>>pq;

        // hash the array 
        unordered_map<int,int>mp;

        for(int n : nums){
            mp[n]++;
        }

        for(auto [n , count] : mp){
            pq.push({count, n});

            if(pq.size() > k)pq.pop();
            
        }

        vector<int>ans;

        while( !pq.empty()){
            int n = pq.top().second;
            
            ans.push_back(n);
            pq.pop();
        }
        return ans;
    }
};