class Solution {
    int count =0;

    void helper(vector<int>&arr, int idx, int target, int sum){
        // baes case
       if(idx == arr.size()){
        if(target == sum)count++;
        return;
       }

        // for each idx we have two choices eiterh add + or -
        helper(arr, idx+1, target, sum+arr[idx]);
        helper(arr, idx+1, target, sum-arr[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums , 0, target, 0);
        return count;
    }
};