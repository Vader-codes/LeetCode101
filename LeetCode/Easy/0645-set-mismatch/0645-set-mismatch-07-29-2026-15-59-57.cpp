class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int x: nums)mp[x]++;

        int missing=0;
        int repeated=0;

        for(int i=1; i<=n; i++){
            if(mp.find(i) == mp.end()){
                // missing no found
                missing =i;
            }
            else if(mp[i] >1) repeated = i;
        }
        return {repeated, missing};
    }
};