class Solution {
    private:
    int solve(int n){
        int one =0;
        while(n != 0){
            if(n%2 !=0)one++;
            n= n/2;
        }
        return one;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++){
            int bits = solve(i);
            ans.push_back(bits);
        }
        return ans;
    }
};