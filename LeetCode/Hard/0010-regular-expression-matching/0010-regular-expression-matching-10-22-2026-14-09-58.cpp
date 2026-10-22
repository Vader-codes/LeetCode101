class Solution {
public:
  int t[21][21];
    bool solve(string &s, string &p, int i, int j) {
        // base case: pattern exhausted
        if (j == p.length()) return i == s.length();

        // check if current characters match
        if(t[i][j]!=-1){
            return t[i][j];
        }
        bool first_char_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        // handle '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // 2 choices: 
            // 1. skip the '*' and its preceding character
            // 2. use '*' to match one more char if first_char_match
            return t[i][j]= solve(s, p, i, j + 2) || (first_char_match && solve(s, p, i + 1, j));
        }

        // if no '*', proceed normally
        return t[i][j]=first_char_match && solve(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {
        memset(t,-1, sizeof(t));
        return solve(s, p, 0, 0);
    }
};
