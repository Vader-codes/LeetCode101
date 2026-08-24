class Solution {
public:
   void expand(string&s, int l, int r, int &start, int &maxLen){
    while(  l>= 0 && r < s.length() && s[l] == s[r]){

        if(r-l+1 > maxLen){
            start = l;
            maxLen = (r-l+1);
        }
        l--;
        r++;
    }
   }
    string longestPalindrome(string s) {
       int start =0;
       int maxLen = 1;
        int n = s.length();
       for(int i=0; i<n; i++){
            // exapnd the odd lenghth 
            expand(s, i, i, start, maxLen);
            // even length palidrome
            expand(s, i, i+1, start, maxLen);
       }
        return s.substr(start, maxLen);
    }
};