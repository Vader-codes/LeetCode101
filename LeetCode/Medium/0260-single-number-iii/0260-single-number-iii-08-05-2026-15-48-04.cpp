class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<int>ans;

        int i =0;
        while( i < n){
            if(i == n-1 || nums[i] != nums[i+1]){
                ans.push_back(nums[i]);
                i++;
            }
            else i+=2;
        }

        return ans;
    }
};