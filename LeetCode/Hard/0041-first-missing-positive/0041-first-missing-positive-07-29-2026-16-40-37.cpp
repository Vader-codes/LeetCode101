class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int x: nums){
            if( x >=0)mp[x]++;
        }
        for(int i=1; i<=n; i++){
            if(mp.find(i)  == mp.end())return i;
        }
        return n+1;
    }
};