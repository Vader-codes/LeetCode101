class Solution {
public:

    int longestValidParentheses(string s) {
        
        int n = s.length();
        int ans =0;
        int left =0;
        int right =0;
        // left to write pass
         for(int i=0; i<n; i++){
            if(s[i] == '(')left++;
             else right++;

            if(left == right){
                ans = max(ans, 2*right);
            }
            if(right > left){
                left = 0;
                right =0;
            }
         }
          left=0;
          right=0;
          // right to left pass
          for(int j=n-1; j>=0; j--){
             if(s[j] == '(')left++;
             else right++;

            if(left == right){
                ans = max(ans, 2*right);
            }
            if(left > right){
                left=0; 
                right=0;
            }

          }
    return ans;
    }
};