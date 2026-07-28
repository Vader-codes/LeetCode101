class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j= n-1;
        int maxi =0;
        while( i < j){
            int area = min(height[i], height[j])*(j-i);
            maxi = max(area, maxi);

            // the decison which pointer to move is based on whihc will not contribute in our answer
            // the minimim or smaller valud has contributed 
            if(height[i] <= height[j])i++;
            else j--;
        }
        return maxi;
    }
};