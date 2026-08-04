class Solution {
private:
    bool canShip(vector<int>& w, int days, int weight) {
        int curr = 0;
        int d = 1;
        for (int i = 0; i < w.size(); i++) {
            if (curr + w[i] <= weight) {
                curr += w[i];
            } else {
                curr = 0;
                d++;
                curr = w[i];
            }
        }
        return (d <= days);
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 0;
        int low = 1;
        for (int x : weights) {
            totalWeight += x;
            low = max(low, x);
        }
        int high = totalWeight;

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                // since we have to find the min weight we do not need right
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};