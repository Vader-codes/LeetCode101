class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int solve(string& a, string& b, int i, int j) {
        // if one string is exhausted we need to delelte the other string
        if (i >= n) {
            int sum = 0;
            for (int k = j; k < m; k++)
                sum += b[k];
                return sum;
        }

        if (j >= m) {
            int sum = 0;
            for (int k = i; k < n; k++) {
                sum += a[k];
            }
            return sum;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if (a[i] == b[j]) {
            // no need to do anything
            return dp[i][j] = solve(a, b, i + 1, j + 1);
        }
        // either delete from a or from b
        int dela = a[i] + solve(a, b, i + 1, j);
        int delb = b[j] + solve(a, b, i, j + 1);

        return dp[i][j] = min(dela, delb);
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.length();
        m = s2.length();

        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};