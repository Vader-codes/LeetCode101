class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        int sum = 0;

        while (j < n) {
            // add current value
            sum += nums[j];
            // what if our sum >= target we have found our anserr
            if (sum >= target) {

                // now this the max arry with sum >= traget we need to find the
                // min so we can shirnk the size until sum>= target;

                while (sum >= target) {
                    int len = (j - i + 1);
                    ans = min(ans, len);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};