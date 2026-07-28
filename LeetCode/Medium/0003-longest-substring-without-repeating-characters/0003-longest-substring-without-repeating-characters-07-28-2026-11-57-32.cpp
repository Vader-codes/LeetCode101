class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans =0;

        for(int i=0; i<n; i++){
            unordered_set<char>st;

            for(int j=i; j<n; j++){
                if(st.find(s[j]) != st.end()) break;

                st.insert(s[j]);
            }
            int len = st.size();
            ans = max(ans, len);
        }
        return ans;
    }
};