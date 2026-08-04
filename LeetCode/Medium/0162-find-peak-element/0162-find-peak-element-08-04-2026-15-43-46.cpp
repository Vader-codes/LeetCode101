class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int peak = -1;
        if(n == 1)return 0;

        for(int i=0; i<n; i++){
            // middle element
         if(i > 0 && i < n-1){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
         }
        else if(i ==0){
            if(nums[i] > nums[i+1]) return i;
         }
          else if(i == n-1 && nums[i] > nums[i-1])return i;
        }
        return -1;
    }
};