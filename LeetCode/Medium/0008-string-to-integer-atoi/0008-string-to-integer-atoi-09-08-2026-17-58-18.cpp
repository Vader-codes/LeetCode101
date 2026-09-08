class Solution {
public:
    int myAtoi(string s) {
        /// remove the trailing whilte space
        int i =0;
        int n = s.size();
        long long ans =0;
        bool isneg = false;
        while( i<n && s[i] == ' ')i++;


        if( i<n && (s[i] == '-'  || s[i] == '+')){
            if(s[i] == '-')isneg = true;
            i++;
        }

        while( i<n && s[i]>='0' && s[i] <='9'){
            int num = s[i]-'0';
            ans= ans*10+num;

            if(!isneg && ans> INT_MAX)return INT_MAX;
            if(isneg && -ans <INT_MIN)return INT_MIN;
            i++;
        }
       return isneg ? -ans:ans;
    }
};