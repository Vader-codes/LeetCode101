class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        // let's do it without the extra space
        int l =0, r=n-1;

        int left_max=0;
        int right_max =0;
        while( l <= r){
            // let's update the left and right max
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);

            if(height[l] <= height[r]){
                // left is  smaller so compute it first 
                ans+= left_max-height[l];
                l++;
            }
            else{
                ans+=right_max - height[r];
                r--;
            }
        }
        return ans;
    }
};