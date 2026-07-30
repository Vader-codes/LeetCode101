class Solution {
    private:
    void reverse_row(vector<int>&arr){
        int i=0, j=arr.size()-1;
        while(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //traverse into the matrix will swap element except where i and j are equal
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse_row(matrix[i]);
        }
        
    }
};