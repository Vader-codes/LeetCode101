class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        typedef pair<int, vector<int>>p;

        priority_queue<p, vector<p>, greater<p>>pq; // min heap {sum, {n1, n2}}
        int n = nums1.size();
        int m = nums2.size();

        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        // we need to keep track of viisted indexes
        set<pair<int,int>>st;
        st.insert({0, 0});

        vector<vector<int>>ans;

        while( k-- && !pq.empty()){
            auto temp  = pq.top(); // kth smallest pair
            pq.pop();
            int i = temp.second[0];
            int j = temp.second[1];

            // we can push this i , j pair to our anser
            ans.push_back({nums1[i], nums2[j]});

            // now we have to try next smallest which is either
            // i, j+1, or i+1, j
            if(j+1 < m && st.find({i, j+1}) == st.end()){
                sum = nums1[i]+ nums2[j+1];
                pq.push({sum, {i, j+1}});
                st.insert({i, j+1});
            }

               if(i+1 < n && st.find({i+1, j}) == st.end()){
                sum = nums1[i+1]+ nums2[j];
                pq.push({sum, {i+1, j}});
                st.insert({i+1, j});
            }


        }
        return ans;
    }
};