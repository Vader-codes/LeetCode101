class Solution {
public:
void solve(vector<int>&arr,  vector<vector<int>>&ans, vector<int>&temp, int idx){
        // base case
        if(idx == arr.size()){
            ans.push_back(temp);
            return;
        }
        // pick an element 
        temp.push_back(arr[idx]);
        solve(arr, ans, temp,idx+1);
        temp.pop_back();
        int next = idx+1;
        while(next < arr.size() && arr[idx] == arr[next])next++;

        solve(arr, ans, temp, next);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums,ans, temp, 0);
        return ans;
    }
};