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

        sort(nums.begin(), nums.end());

        vector<int>ans;
        for(int i=1; i<=n; i++){
            if(!present(i, nums)) ans.push_back(i);
        }

        return ans;
    }
};