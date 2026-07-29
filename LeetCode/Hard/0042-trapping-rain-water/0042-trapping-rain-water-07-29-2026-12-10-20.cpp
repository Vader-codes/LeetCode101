class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
         // now let try to find the right and left max for every building beforehand
         vector<int>nge(n, 0);
         vector<int>pge(n, 0);

         // let's make next greater element
         int next_g = height[n-1]; 
         for(int i=n-1; i>=0; i--){
            next_g = max(next_g, height[i]);
            nge[i] = next_g;

         }
         // previous greater element
         int prev_g = height[0];
         for(int i=0; i<n; i++){
            prev_g = max(prev_g, height[i]);
            pge[i] = prev_g;
         }

         for(int i=0; i<n; i++){
            int area = min(pge[i], nge[i])-height[i];
            ans+=area;
         }
        return ans;
    }
};