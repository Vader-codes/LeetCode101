class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
       unordered_map<int,int>mp;
       for(int x : nums) mp[x]++; // we have hashed the nums into the map

        vector<int>ans;

        for(int i=1; i<=n; i++){
            // checkif the number is present into the map
            if(mp.find(i) == mp.end()) {
                // not present
                ans.push_back(i);
            }
        }

        return ans;
    }
};