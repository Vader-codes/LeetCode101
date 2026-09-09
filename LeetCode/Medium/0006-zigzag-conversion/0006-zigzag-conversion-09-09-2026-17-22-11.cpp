class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
         if (numRows == 1 || numRows >= (int)s.size()) return s;
         vector<string>rows(numRows);
         int direction =1;
         int curRow =0;


         for(char  c : s){
            rows[curRow]+=c;

            if(curRow == 0)direction =1;
            else if(curRow == numRows-1)direction = -1;
            curRow+=direction;
         }
         string ans ="";
         for(auto row : rows){
            ans +=row;
         }
         return ans;
    }
};