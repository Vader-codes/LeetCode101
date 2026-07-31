class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // step 1 check if beginWord and endWord are the same
        if(beginWord == endWord)return 0;


        // step 2 : hash all the wordList into a set

        unordered_set<string>st;
        for(auto w : wordList)st.insert(w);
        if(st.find(endWord) == st.end())return 0;

        // step 3 we are doing a bfs for every combination from beginword to endwornd that are int wordList
        queue<pair<int,string>>q;
        q.push({1, beginWord});
        int ans =0;
        while(!q.empty()){
            auto[step, word] = q.front();
            q.pop();

            if(word == endWord){
                return step;
            }

            int n = word.length();
            for(int i=0; i<n; i++){
                char ch = word[i];
                vector<string>temp;

                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    // we have to check for a cominaiton 
                    if(st.find(word) != st.end()){
                        q.push({step+1, word});
                        temp.push_back(word);
                        // remove from the set
                    }         

                }
                // delete the words form the sst
                for(auto t : temp)st.erase(t);
                // change the back the word whih we changed
                word[i] = ch;
            }
        }
        return ans;
    }
};