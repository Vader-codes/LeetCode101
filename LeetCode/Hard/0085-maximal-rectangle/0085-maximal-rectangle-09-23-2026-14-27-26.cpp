class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int ans =0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                // i can say we have got our next smaller which is heights[i]; \
                and previous smaller for st.top() which is after st.top()
                int nse = i;
                int h = heights[st.top()];st.pop();
                int pse = st.empty() ? -1 : st.top();
                int area = h*(nse-pse-1);
                ans = max(ans, area);
            }
            st.push(i);
           
        }
        
            while(!st.empty()){
                int nse = n;
                int h = heights[st.top()]; st.pop();
                int pse = st.empty() ? -1 : st.top();
                int area  = h*(nse-pse-1);
                ans = max(ans, area);
            }
        
        return ans;
 }
    int maximalRectangle(vector<vector<char>>& matrix) { 
        int ans= 0;
        int n = matrix.size();
        int m = matrix[0].size();

         vector<int> height(m, 0);
         for(int i=0; i<n; i++){
            // calcualte the height for each row
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else height[j]=0;
            }
            int area = largestRectangleArea(height);
            ans = max(ans,area);
         }
        return ans;
    }
};