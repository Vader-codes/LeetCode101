class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // step 1 hash the deadends into a set
        unordered_set<string> st;

        for (auto& d : deadends)
            st.insert(d);


        string com = "0000"; // starting combination
        if (target == com)
            return 0;
        // check if 0000 is in the dead end
        if(st.find(com) != st.end())return -1;
        unordered_set<string>vis;
        vis.insert("0000");

        queue<pair<int, string>> q;
        q.push({0, com});

        while (!q.empty()) {
            auto [step, state] = q.front();
            q.pop();

            if (state == target)
                return step;

            for (int i = 0; i < 4; i++) {
                char ch = state[i];
                // for each position we can move +1 and -1 
                // forward rotation
                state[i] = (ch == '9') ? '0' : ch+1;
                // check for valid state
                if(!st.count(state) && !vis.count(state)){
                    vis.insert(state);
                    q.push({step+1, state});
                }

                // rotate backwards
                state[i] = (ch == '0') ? '9' : ch-1;
                if(!st.count(state) && !vis.count(state)){
                    vis.insert(state);
                    q.push({step+1, state});
                }

                //restore
                state[i] = ch;
            }
        }

        return -1;
    }
};