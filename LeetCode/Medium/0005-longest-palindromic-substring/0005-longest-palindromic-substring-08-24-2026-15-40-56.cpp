class Solution {
public:
bool isPal(string &s, int i, int j){
    if(i >= j)return true;
    if(s[i] != s[j])return false;

    return isPal(s, i+1, j-1);
}
    string longestPalindrome(string s) {
        string ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPal(s, i, j)) {
                    int len = (j - i + 1);
                    if (len > ans.size()) {
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        return ans;
    }
};