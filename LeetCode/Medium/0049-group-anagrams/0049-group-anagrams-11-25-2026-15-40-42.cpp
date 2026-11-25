class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>>mp;
        for(int i = 0; i< strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto [s, it] : mp){
            vector<string>temp;
            for(int i=0; i<it.size(); i++){
                temp.push_back(it[i]);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};