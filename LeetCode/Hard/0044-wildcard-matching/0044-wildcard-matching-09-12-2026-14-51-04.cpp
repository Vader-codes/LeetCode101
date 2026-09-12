class Solution {
public:
int n, m;
 int dp[2001][2001];
  bool solve(string&a, string&b, int i , int j){
    // base cases
    if(i >= n && j>=m )return true;
    if(i < n && j >=m)return false;
    if(i >=n && j < m){
        // if we have any other character than * it is false else true
        for(int k=j; k<m; k++){
            if(b[k] != '*')return false;
        }
        return true;
    }
    if(dp[i][j] != -1)return dp[i][j];
    // either its is mathcing or ?
    if(a[i] == b[j] || b[j] == '?')return dp[i][j] =solve(a, b, i+1 , j+1);

   if(b[j] == '*')return dp[i][j] =solve(a, b, i+1, j) || solve(a, b, i, j+1); // either match with one or skip
   return dp[i][j]= false;

  }
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, p, 0 ,0);
    }
};