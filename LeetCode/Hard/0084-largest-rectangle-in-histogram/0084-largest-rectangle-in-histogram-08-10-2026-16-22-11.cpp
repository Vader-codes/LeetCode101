class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int>st;

        int  n = heights.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
           while(!st.empty() && heights[st.top()] > heights[i]){
            int element = heights[st.top()]; st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int area =  element*(nse - pse -1);
            ans = max(ans, area);
           }
           st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int h = heights[st.top()]; st.pop();
            int pse = st.empty()? -1 : st.top();
            int area =  h*(nse - pse -1);
            ans = max(ans, area);
        }
        return ans;
    }
};