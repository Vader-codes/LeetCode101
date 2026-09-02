class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n= nums.size();

        for(int i=0; i<n; i++){
            int jump = nums[i];
            if(i > maxReach)return false;

            maxReach = max(maxReach, i+jump);
            if(maxReach >= n-1)return true;
        }
        return false;
        
    }
};