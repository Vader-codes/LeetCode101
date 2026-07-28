class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0, j=0;
        int ans = 0;
        int zero =0;

        while( j < n ){
            // check if it is a zero
            if(nums[j] == 0)zero++;

            // now check if we are exceeding the k zero limit
            while(zero > k){
                if(nums[i] == 0)zero--;
                i++;
            }
            // since the zeroes < k it is  a valid window
            int len = (j-i+1);
            ans = max(ans, len);
            j++;
        }

        return ans;
    }
};