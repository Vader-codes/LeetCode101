class Solution {
public:
 void solve(vector<int>& arr, int target,   vector<vector<int>>&ans, vector<int>&temp , int idx ){
     // base case
        if(idx >= arr.size()){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            return;
        }


     if(arr[idx] <= target){
        temp.push_back(arr[idx]);
        solve(arr, target-arr[idx], ans, temp, idx+1);
        temp.pop_back();
     }
     // we need to get rid of the duplicats
     int next = idx+1;
     while(next < arr.size() && arr[idx] == arr[next])next++;
     solve(arr, target, ans, temp, next);
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
         vector<vector<int>>ans;
         vector<int>temp;
         sort(candidates.begin(), candidates.end());
         solve(candidates, target , ans, temp, 0);

         return ans;
    }
};