class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // step 1 hash the nums into a map [freq, elemnt] pair
        unordered_map<int, int> mp;
        typedef pair<int,int>p;
        for (int x : nums)
            mp[x]++;

        // now get the pair inside a vector as [freq, element]
        vector<pair<int, int>> arr;
        for (auto& it : mp) {
            int f = it.second;
            int e = it.first;

            arr.push_back({f, e});
        }
        // let use the priority queue or min priority queue
        priority_queue<p, vector<p>, greater<p>>pq;

        for(auto &it : mp){
            pq.push({it.second, it.first});

            if(pq.size() > k)pq.pop();
        }
        // get the answer from the pq
        vector<int>ans;
        while(!pq.empty()){
            auto[key, value] = pq.top(); pq.pop();
            ans.push_back(value);
        }
        
        return ans;
    }
};