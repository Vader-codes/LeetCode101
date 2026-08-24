class Solution {
public:
 bool isPal(string &s, int i , int j){

    while( i < j){
        if(s[i] != s[j])return false;

        i++;
        j--;
    }
    return true;
 }
    int countSubstrings(string s) {
        int ans =0;
        int n = s.length();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPal(s, i, j))ans++;
            }
        }
        return ans;
    }
};