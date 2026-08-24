class Solution {
public:
int dp[1001][1001];
    int n, m;
    int solve(string &a, string &b, int i, int j){
        if(i == n || j == m)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j]=1+solve(a, b, i+1, j+1);
        }
        else {
            return dp[i][j] = max(solve (a, b, i+1, j) , solve(a, b, i, j+1) );
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0 ,0);
    }
};