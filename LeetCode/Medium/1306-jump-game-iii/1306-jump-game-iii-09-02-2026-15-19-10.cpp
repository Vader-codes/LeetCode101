class Solution {
public:
 bool solve(vector<int>&arr, int idx,  vector<int>&vis){
    // base case
    if(idx < 0 )return false;
    if(idx >= arr.size()) return false;

    if(vis[idx])return false;

    if(arr[idx] == 0)return true;

    vis[idx] = true;

    // from this idx we can go idx+arr[idx], idx-arr[idx];

    return solve(arr, idx+arr[idx], vis) || solve(arr, idx-arr[idx] , vis);
 }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n, false);
        return solve(arr, start, vis);
    }
};