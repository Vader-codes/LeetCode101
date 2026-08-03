class Solution {
    private:
    vector<vector<int>>ans;
    void solve(int idx, int n, vector<int>&nums, int target, vector<int>&temp){
        // if the target is 0 then return
        if(idx >=n)return;
        if(target ==0){
            ans.push_back(temp);
            return;
        }
        // pick the currenct element only if it is smaller than target
        if(nums[idx] <= target){
            temp.push_back(nums[idx]);
            solve(idx, n, nums, target-nums[idx], temp);
            temp.pop_back();
        }
        // skip the current element
        
        solve(idx+1, n, nums, target, temp);

        
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n  = candidates.size();
        vector<int>temp;
        solve(0, n, candidates, target, temp);
        return ans;
    }
};