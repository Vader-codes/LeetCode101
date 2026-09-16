class Solution {
   vector<vector<int>>ans;
 
    private:
    void solve(int idx, int n, vector<int>& nums){
        if(idx == n){
            // reached to the end
            ans.push_back(nums);
            return;
        }
               unordered_set<int>st;
        // try different numberes for this idx position
        for(int i=idx; i<n; i++){
            // check if i already exists of not
            if(st.find(nums[i]) != st.end())continue;

            // put the current element into the set
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            // now explore
            solve(idx+1, n, nums);
            // now retrive back to original
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
      solve(0, n, nums);
      return ans;
    }
};