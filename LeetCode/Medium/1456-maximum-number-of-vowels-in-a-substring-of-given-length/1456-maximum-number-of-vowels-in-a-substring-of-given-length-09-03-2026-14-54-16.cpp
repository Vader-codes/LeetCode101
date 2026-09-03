class Solution {
public:
  bool isVowel(char ch){
    return (ch == 'a' || ch =='e' || ch=='i' || ch == 'o' || ch == 'u');
  }
    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int count =0;
        int l=0, r=0;
        while(r < n){
            if(isVowel(s[r]))count++;

            int len = (r-l+1);
            if(len == k){
                // calculate the ans
                ans = max(ans, count);
                //move the both l and r if l is a vowel redue the count

                if(isVowel(s[l]))count--;
                l++;
                r++;
            }
            else r++;
        }
        return ans;
    }
};