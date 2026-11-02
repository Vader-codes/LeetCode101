class Solution {
public:
    int search(vector<int>& nums, int target) {
     int idx =-1;
     int n = nums.size();
    int i=0, j=n-1;

        while( i<=j){
            int mid = (i+j)/2;

            if(nums[mid]== target){
                idx = mid;
                break;
            }
            else if(nums[mid] >target){
                j=mid-1;
            }
            else{
                i= mid+1;
            }
        }
     return idx;   
    }
};