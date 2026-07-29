class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    

         for(int i=0; i<=n; i++){
            bool find = false;
            for(int j=0; j<n; j++){
                if(nums[j] == i){
                     find = true;
                     break;
                }
            }

            if(!find)return i;
         }

        return -1;
    }
};