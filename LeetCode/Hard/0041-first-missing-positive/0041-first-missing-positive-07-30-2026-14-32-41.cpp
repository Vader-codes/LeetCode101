class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 1;
        for(int x : nums){
            // if x is negative or 0 skip it 
            if(x<=0)continue;
             if(x == ans)ans++;
            else if(x > ans)break;
        }
        return ans;

    }
};