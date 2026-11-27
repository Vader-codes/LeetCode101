class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // lets use bucket sort
        vector<vector<int>> bucket(nums.size() + 1);

        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto [n, count] : mp) {
            bucket[count].push_back(n);
        }
        vector<int> ans;

        for (int i = nums.size(); i >0 && ans.size() <k; i--) {

            for (int n : bucket[i]) {
                ans.push_back(n);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};