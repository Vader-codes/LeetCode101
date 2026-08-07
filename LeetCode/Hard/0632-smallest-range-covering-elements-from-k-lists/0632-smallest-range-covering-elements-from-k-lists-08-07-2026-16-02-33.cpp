class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef   pair<int,pair<int,int>>p;     //{nums[i], {row, idx}}
        priority_queue<p, vector<p>, greater<p>>pq;

        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            pq.push({nums[i][0], {i,0}});
            maxi = max(maxi, nums[i][0]);
        }

        int bestL=pq.top().first;
        int bestR = maxi;

        while(!pq.empty()){
           auto temp = pq.top();
           pq.pop();
           int mini = temp.first;
           int row = temp.second.first;
           int col = temp.second.second;

           // current range
           if(maxi - mini < bestR - bestL){
            bestL = mini;
            bestR = maxi;
           }
           if(col+1 == nums[row].size())break;

           int next = nums[row][col+1];
           pq.push({next, {row, col+1}});
           maxi = max(maxi , next);
        }
        return {bestL, bestR};
    }
};