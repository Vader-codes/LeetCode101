class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        list<int>li;
        vector<int>ans; // to store the answer

        while( j< n){
            // we need to add this j element into the list but with certain 
            // conditions 
            // if there is a smaller element in the list we need to pop it 
            // because it serves no purpost when we have somehing which is greater than that
            while(li.size() >0 && li.back() < nums[j]){
                li.pop_back();
            }
        // now we can push the j
         li.push_back(nums[j]);
            int len = (j-i+1);

            if(len == k){
              // we are sure that the first value in our  list is the max value
              ans.push_back(li.front());
              // now we have to shirnk the window what if i is the max elemne t
              // we have to remove it from the list tooo
              if(li.front() == nums[i]) 
                li.pop_front();

                i++;
            }
            j++;

        }
        return ans;
    }
};