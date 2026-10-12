class Solution {
    bool find_target(vector<vector<int>>& matrix, int row , int m , int t){
        int low =0;
        int high = m-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(matrix[row][mid] == t)return true;
            else if(matrix[row][mid] > t)high = mid-1;
            else low = mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            if(find_target(matrix, i, m,target))return true;
        }
        return false;
    }
};