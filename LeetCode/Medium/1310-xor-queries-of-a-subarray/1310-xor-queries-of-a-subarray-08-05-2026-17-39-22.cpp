class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = arr.size();
        vector<int>xr(n, 0);
        xr[0] = arr[0];
        for(int i=1; i<arr.size(); i++){
            xr[i] =  xr[i-1]^arr[i];
        }
        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];

             int xor_r = xr[r]^ (l == 0 ? 0:xr[l-1]);
             ans.push_back(xor_r);
        }

       
        return ans;
    }
};