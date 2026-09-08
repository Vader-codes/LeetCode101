class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans =0;
        int i=0, j=0;

        unordered_map<char,int>mp;

        while( j < n){
            // push the char into the map
            mp[s[j]]++;
            // what if s[j] already exists we need to shrink 

            while(mp[s[j]] > 1){
                // need to shrink 
                mp[s[i]]--;

                // if it becomes 0 remove it
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }

          
            int len = (j-i+1);

            ans = max(ans, len);
            j++;

        }
       
        return ans;
    }
};