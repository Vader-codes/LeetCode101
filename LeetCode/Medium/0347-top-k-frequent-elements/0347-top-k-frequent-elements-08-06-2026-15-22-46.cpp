class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // step 1 hash the nums into a map [freq, elemnt] pair
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        // now get the pair inside a vector as [freq, element]
        vector<pair<int, int>> arr;
        for (auto& it : mp) {
            int f = it.second;
            int e = it.first;

            arr.push_back({f, e});
        }
        // now sort it accorin gto the frequenc

        sort(arr.begin(), arr.end());

        // get the answer
        vector<int> ans;
        int i=arr.size()-1;
        while( k >0){
             ans.push_back(arr[i].second);
             i--;
             k--;
        }
        return ans;
    }
};