class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>lis(n, 1);
        vector<int>count(n, 1);
        int maxi =1;
        for(int i=0; i<n; i++){

            for(int j=0; j<i; j++){

                // now check if it is increasing 
                if(nums[j] < nums[i]){
                 if(lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1;
                    count[i] = count[j];
                 }
                 else if(lis[j]+1 == lis[i]){
                    count[i]+=count[j];
                 }
                }
            }
            maxi = max(maxi, lis[i]);
        }
        int ans= 0;
        for(int i=0; i<n; i++){
            if(lis[i] == maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
};