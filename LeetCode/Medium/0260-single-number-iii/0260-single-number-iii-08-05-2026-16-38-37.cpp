class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      long long xr = 0;
      for(int x: nums) xr = xr^x;

      // mask ->rightmost set bit
      int mask = (xr)&(-xr);
      int groupa =0;
      int groupb =0;

      for(int &n : nums){

        if(mask & n){
            groupa = groupa^n;
        }
        else groupb  = groupb^n;
      }

        

        return {groupa, groupb};
    }
};