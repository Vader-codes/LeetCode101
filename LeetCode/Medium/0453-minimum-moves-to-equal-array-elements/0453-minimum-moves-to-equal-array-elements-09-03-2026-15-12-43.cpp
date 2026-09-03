class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(int x : nums)mini = min(mini, x);

        int ans = 0;
        for(int n : nums){
            ans += n-mini;
        }
        return ans;
    }
};