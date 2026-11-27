class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;

        // hash the array 
        unordered_map<int,int>mp;

        for(int n : nums){
            mp[n]++;
        }

        for(auto [n , count] : mp){
            pq.push({count, n});
        }

        vector<int>ans;

        while( !pq.empty() && k > 0){
            int n = pq.top().second;
            
            ans.push_back(n);
            pq.pop();
            k--;
        }
        return ans;
    }
};