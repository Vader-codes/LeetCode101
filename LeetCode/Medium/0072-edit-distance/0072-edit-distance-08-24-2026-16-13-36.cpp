class Solution {
public:
int n, m;
int dp[501][501];
int solve(string &a, string&b, int i,int j){

    if(i >= n )return m-j;
    if(j >= m)return n-i;

    if(dp[i][j] != -1)return dp[i][j];
    if(a[i] == b[j])return solve(a, b, i+1, j+1);

    int del = 1+solve(a, b, i+1, j);
    int insert = 1+solve(a,b, i, j+1);

    int replace = 1+solve(a, b, i+1, j+1);
    return dp[i][j] =min({del, insert, replace});

}
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
        
    }
};