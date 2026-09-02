class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxi =0;
        sort(tokens.begin(), tokens.end());

        int n = tokens.size();

        int i=0, j=n-1;

        int score = 0;
        while(  i <= j){
            // play face up
            if(tokens[i] <= power){
                score++;
                maxi = max(maxi, score);
                power -= tokens[i];
                i++;
            }
            else if(tokens[i] > power && score > 0){
                power +=tokens[j];
                j--;
                score--;
            }
            else break;
        }
        return maxi;
    }
};