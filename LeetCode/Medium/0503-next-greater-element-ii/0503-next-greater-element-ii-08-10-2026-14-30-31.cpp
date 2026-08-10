class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>nge(n, 0);
        for(int i=n-1; i>=0; i--){
            if(st.empty())st.push(nums[i]);

            else if(nums[i] < st.top()){
                st.push(nums[i]);
            }
            else if(nums[i] >= st.top()){
                while(!st.empty() && st.top() <= nums[i])st.pop();

                st.push(nums[i]);
            }
        }
        for(int i=n-1; i>=0; i--){
            if(st.empty())nge[i] = -1;

            else if(st.top() > nums[i])nge[i] = st.top();

            else if(st.top() <= nums[i]){
                while(!st.empty() && st.top() <= nums[i])st.pop();

                nge[i] = st.empty()? -1 : st.top();
            }

            st.push(nums[i]);
        }

        return nge;
    }
};