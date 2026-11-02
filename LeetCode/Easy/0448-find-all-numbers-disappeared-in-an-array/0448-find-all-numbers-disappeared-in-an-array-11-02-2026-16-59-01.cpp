class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        // use cycle sort instead

        int i=0;
        while( i < n){
            int correct = nums[i]-1;

            if(nums[i] != nums[correct])swap(nums[i], nums[correct]);

            else i++;
        }
        vector<int>ans;
       for(int i=0; i<n; i++){
        if(i+1 != nums[i])ans.push_back(i+1);
       }
        return ans;
    }
};