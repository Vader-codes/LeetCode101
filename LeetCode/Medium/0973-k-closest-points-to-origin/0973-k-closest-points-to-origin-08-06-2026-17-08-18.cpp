class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>>pq; //{dist, {x, y}} max heap

        for(auto &p : points){
            int dist =  p[0]*p[0]+p[1]*p[1];

           pq.push({dist, {p[0], p[1]}});
           if(pq.size() > k)pq.pop();
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            auto[key, cordinates] = pq.top();
            ans.push_back({cordinates.first, cordinates.second});
            pq.pop();
        }
        return ans;
    }
};