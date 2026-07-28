class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n =  nums.size();
        int i=0, j=0;
        int ans =0;
        if(k == 0)return 0;
        if(k == 1)return 0;

        int product = 1;

        while( j <  n ){
            product = product * nums[j];

            // keep the window valid
            while( product >= k){
                product = product/nums[i];
                i++;

            }// the size of valid window
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};