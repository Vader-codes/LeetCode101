class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;

      for(auto &s : words)mp[s]++;

        vector<vector<string>>bucket(words.size()+1);
        for(auto& [w , count] : mp){
            bucket[count].push_back(w);
        }

        vector<string>ans;
        for(auto &b : bucket){
            sort(b.begin(), b.end());
        }

        for(int i=bucket.size()-1; i>0 && ans.size() < k; i--){

            for(string s : bucket[i]){
                ans.push_back(s);

                if(ans.size() == k)break;
            }
        }

        return ans;
    }
};