class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans =0;

       for(int bit=0; bit<=31; bit++){
          int count =0;
          for(int i=0; i<nums.size(); i++){
             // check if the i the bit is set or not in all the numbers
             if(nums[i] &(1 << bit)) count++;
          }
          if( count % 3 != 0){
            // that bit has to set in the anslk
          ans = ans|(1 << bit);
          }
       }
       return ans;
    }
};