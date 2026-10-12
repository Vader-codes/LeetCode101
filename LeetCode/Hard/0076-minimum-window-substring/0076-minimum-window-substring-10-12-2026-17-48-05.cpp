class Solution {
    bool isValid(vector<int>& a, vector<int>& b) {
        bool valid = true;
        for (int k = 0; k < 124; k++) {
            if (a[k] < b[k]) {
                valid = false;
                break;
            }
        }
        return valid;
    }

public:
    string minWindow(string s, string t) {
        int n = s.length();
        vector<int> t_hash(124, 0);
        vector<int> s_hash(124, 0);
        // hash t
        for(char c: t){
            t_hash[c]++;
        }
        int s_idx = 0;
        int e_idx =0;
        int i = 0, j = 0;
        int len =0;
        string ans = "";
        while (j < n) {
            s_hash[s[j]]++;

            // we have to check if the current window is a valid one
            while (isValid(s_hash, t_hash)) {
                 
                if ( len == 0 || (j-i+1) < len) {
                    len = j-i+1;
                    s_idx = i;
                    e_idx = len;
                }
                // now shrink the window
                s_hash[s[i]]--;
                i++;
            }

            j++;
        }
        return s.substr(s_idx, e_idx);
    }
};