class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();

        unordered_map<int,int>mp;
        int i=0, j=0;
        int ans =0;
        while( j < n){
            // first push tthe current fruit into the map
            mp[fruits[j]]++;

            // we have to maintain the size <=2
            // we have to pop some fruits out
            while( mp.size() > 2){
                mp[fruits[i]]--;

                // if the freq becomes 0 then remove it form the map

                if(mp[fruits[i]] == 0)mp.erase(fruits[i]);

                i++;
            }
            // now its a valid window of two unique fruits 
            // calcuate the size of our basket
            int len = (j-i+1);
            ans = max(ans, len);
            j++; // move forward
        }
    return ans;

    }
};