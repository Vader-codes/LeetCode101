class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left_candy(n, 1);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left_candy[i] = 1 + left_candy[i - 1];
            }
        }
      vector<int> right_candy(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n-1 && ratings[i] > ratings[i + 1]) {
                right_candy[i] = 1 + right_candy[i + 1];
            }
        }
        int candy =0;
        for(int i=0; i<n; i++){
            int maxCandy = max(left_candy[i], right_candy[i]);
            candy+=maxCandy;
        }
        return candy;
    }
};