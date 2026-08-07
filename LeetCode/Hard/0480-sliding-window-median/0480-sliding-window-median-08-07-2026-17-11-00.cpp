class Solution {
public:
    multiset<int> left;   // smaller half
    multiset<int> right;  // larger half

    void balance() {
        if (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            right.insert(*it);
            left.erase(it);
        }
        else if (right.size() > left.size()) {
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }
    }

    void add(int x) {
        if (left.empty() || x <= *left.rbegin()) {
            left.insert(x);
        }
        else {
            right.insert(x);
        }

        balance();
    }

    void remove(int x) {
        auto it = left.find(x);

        if (it != left.end()) {
            left.erase(it);
        }
        else {
            it = right.find(x);

            if (it != right.end()) {
                right.erase(it);
            }
        }

        balance();
    }

    double getMedian() {
        if (left.size() == right.size()) {
            return ((long long)*left.rbegin() +
                    (long long)*right.begin()) / 2.0;
        }

        return *left.rbegin();
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;

        // First window
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }

        medians.push_back(getMedian());

        // Slide window
        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            add(nums[i]);

            medians.push_back(getMedian());
        }

        return medians;
    }
};