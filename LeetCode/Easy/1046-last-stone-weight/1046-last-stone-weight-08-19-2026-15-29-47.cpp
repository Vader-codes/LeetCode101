class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>q;
        for(int x : stones){
            q.push(x);
        }

        while(!q.empty() && q.size() > 1){
            int s1 = q.top(); q.pop();
            int s2 = q.top(); q.pop();

            int newStone = s1-s2;
            q.push(newStone);
        }

        return q.empty() ? 0 : q.top();
    }
};