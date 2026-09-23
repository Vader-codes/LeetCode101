class Solution {
    private:
    int solve(int idx, string& s, vector<int>&dp){
        // reached the end
            if(idx == s.size()){
                return 1;
            }
        // a decoding cannot start with 0
        if(s[idx] == '0')return 0;
        if(dp[idx] != -1)return dp[idx];
        // take one digit
        int way = solve(idx+1, s, dp);

        // take two digits
        if(idx+1 < s.size()){
            int num = (s[idx] -'0')*10 + (s[idx+1] - '0');
            if(num >=10 && num<=26){
                way+= solve(idx+2, s, dp);
            }
        }
        return dp[idx] =way;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, -1);
        return solve(0, s, dp);
    }
};