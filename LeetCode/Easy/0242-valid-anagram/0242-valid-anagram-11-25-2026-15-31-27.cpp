class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())return false;

        int n = s.length();
        vector<int>freq(27, 0);

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        
       for(int i=0; i<n; i++){
            freq[t[i]-'a']--;
        }

        for(int i=0; i<27; i++){
            if(freq[i] !=0)return false;
        }
        

        return true;
        
    }
};