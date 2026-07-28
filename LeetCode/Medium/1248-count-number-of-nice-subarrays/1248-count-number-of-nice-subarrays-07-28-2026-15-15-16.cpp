class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;

        int ans =0;
        int odd =0;
        int count =0;
        while( j< n ){
            if(nums[j] % 2 !=0)odd++;

            if(odd == k){
                 count =0;
                 while(odd == k){
                    count++;
                    if(nums[i] %2 !=0) odd--;
                    i++;
                 }
            }
              ans+=count;
            j++;
        } 
        return ans;  
    }
};