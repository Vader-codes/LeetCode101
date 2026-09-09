class Solution {
  vector<vector<int>>ans;
    private:
    int two_sum(vector<int>& nums, int i, int j, int target){
        while(i < j){

            if(nums[i] + nums[j] == target){
             ans.push_back({-target, nums[i], nums[j]});

            while(  i<j && nums[j] == nums[j-1]) j--;
            while( i<j && nums[i] == nums[i+1])i++;
            i++;
            j--;
            }
            else if(nums[i] + nums[j] < target)i++;
            else j--;
        }
        return 0;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if( n < 3)return {};

        ans.clear();
        sort(nums.begin(), nums.end());
         for(int i=0; i<n; i++){
            if( i>0 && nums[i] == nums[i-1])continue;
            int target = -nums[i];

            two_sum(nums, i+1, n-1, target);
         }

         return ans;
        
    }
};