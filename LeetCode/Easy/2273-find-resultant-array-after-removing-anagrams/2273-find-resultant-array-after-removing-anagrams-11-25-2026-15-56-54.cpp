class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
    
        vector<string>ans;
        string prevsorted = "";

        for(string w : words){
            string sorted = w;
            sort(sorted.begin(), sorted.end());

            if(sorted != prevsorted){
                ans.push_back(w);
                prevsorted = sorted;
            }
        }
        
        return ans;
    }
};