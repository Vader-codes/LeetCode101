class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        // things to notice i< j indexes i<= j values and width = j-i
        // so lets come from left to right first and keet the elements in ascending order
        stack<int>st;
        for(int i=0; i<n; i++){
            if(st.empty() || nums[i] < nums[st.top()])
            st.push(i);
        }
        // now come right to left 
        // since beause we have elements from smallest to gretest 
        // wo we can comparet the last leement with the smalles to the left
        int ramp =0;
        for(int i=n-1; i>=0; i--){
            // when we can have a answer
            while( !st.empty() && nums[st.top()] <= nums[i] ){
                // it could be ans annswer
                ramp = max(ramp, i-st.top());
                st.pop(); // find more smallest if possible
            }
        }
        return ramp;
    }
};