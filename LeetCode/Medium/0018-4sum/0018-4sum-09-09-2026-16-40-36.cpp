class Solution {
    private:
     vector<vector<int>>result;
     void two_sum(vector<int>& nums, int i, int j, int n1, int n2, int t){
        while( i< j){
             long long sum = (long long)nums[i]+nums[j]+ n1+n2;

             if(sum < t)i++;
             else if(sum > t)j--;
             else{
                result.push_back({n1, n2, nums[i], nums[j]});

                while(i<j && nums[i] == nums[i+1])i++;
                while( i<j && nums[j] == nums[j-1])j--;

                i++;
                j--;
             }
        }
     }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

            result.clear();
        for(int i=0; i<n; i++){
            if( i>0 && nums[i] ==nums[i-1])continue;

            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;
                two_sum(nums, j+1, n-1, nums[i], nums[j], target);
            }

        }
        return result;
    }
};