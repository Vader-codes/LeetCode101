class Solution {
    private:
    bool present(int num, vector<int>&arr){
        // use binary search to find a no is present or not in a sorted array
        int low=0, high = arr.size()-1;

        while(low<=high){
            int mid = low+(high - low)/2;

            if(arr[mid] == num)return true;
            if(arr[mid] < num) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
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