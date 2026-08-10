class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n = temperatures.size();
         vector<int>ans;
         stack<int>st;
         for(int i = n-1; i>=0; i--){
            if(st.empty()){
                ans.push_back(0);
                st.push(i);
            }
            else{
                // what happens over here is our stack is not empty \
                we are coming from the right so we know what we saw on the right \
                now just comapare our find out the greater element that current \
                from the stack if any
                 int idx = st.top();
                 if(temperatures[idx] > temperatures[i]){
                    ans.push_back(idx - i);
                    st.push(i);
                 }
                 else{
                    while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                        st.pop();
                    }
                    if (!st.empty() && temperatures[st.top()] > temperatures[i]){
                        ans.push_back(st.top() - i);

                    }
                    else{
                        ans.push_back(0);
                    }
                    st.push(i);

                 }

                
            }
         }
         reverse(ans.begin(), ans.end());
         return ans;
    }
};