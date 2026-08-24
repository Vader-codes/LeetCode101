class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int helper(string& a, string& b, int i, int j) {

        if (j == m)
            return 1;
        if (i == n)
            return 0;

            if(dp[i][j] != -1)return dp[i][j];
        if (a[i] == b[j]) {

            return dp[i][j]= helper(a, b, i + 1, j + 1) + helper(a, b, i + 1, j);
        }

        return dp[i][j] =helper(a, b, i + 1, j);
    }
    int numDistinct(string s, string t) {

        n = s.length();
        m = t.length();

        memset(dp, -1, sizeof(dp));
        return helper(s, t, 0, 0);
    }
};