class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>>temp;

        for(auto &p : points){
            int dist =  p[0]*p[0]+p[1]*p[1];

            temp.push_back({dist, p});
        }

        sort(temp.begin(), temp.end());
        vector<vector<int>>ans;
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};