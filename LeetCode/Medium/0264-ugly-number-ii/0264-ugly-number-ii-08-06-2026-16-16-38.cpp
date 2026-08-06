class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> st;

        pq.push(1);
        st.insert(1);
        long long num = 0;
        int i = 0;
        while (i < n) {
            num = pq.top();
            pq.pop();

            if (st.find(num * 2) == st.end())
                pq.push(num * 2);
            if (st.find(num * 3) == st.end())
                pq.push(num * 3);
            if (st.find(num * 5) == st.end())
                pq.push(num * 5);

            st.insert(num * 2);
            st.insert(num * 3);
            st.insert(num * 5);
            i++;
        }
        return (int)num;
        //         "The loop runs exactly n times because we pop one ugly number
        //         in each iteration. Each iteration performs one pop and at
        //         most three push operations on the priority queue. Since the
        //         priority queue contains O(n) elements, each push/pop takes
        //         O(log n) time. The unordered_set operations are O(1) on
        //         average. Therefore, the total time complexity is O(n log n)."

        // If they ask about space:

        // "The priority queue and the unordered_set both store at most O(n)
        // unique ugly numbers, so the space complexity is O(n)."

        // If the interviewer asks, "Why is the heap size O(n)?"

        // You can answer:

        // "We perform exactly n iterations. In each iteration, we remove one
        // element and insert at most three new unique elements. So the heap
        // grows linearly with n, and its size is bounded by O(n)."
    }
};