class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if(num1 == "0" || num2 == "0")return "0";

        vector<int>arr(n1+n2, 0);
        //multiply every digit of num1 with evety digit of num2;
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){

                int product = (num1[i]-'0') * (num2[j] -'0');
                int sum = product + arr[i+j+1];
                // store the last digit
                arr[i+j+1] = sum%10;
                
                // carrry goes to one position before 
                arr[i+j] +=sum/10;

            }
        }
        string ans = "";
        int i=0;
        // skip the leading zeroes
        while( i<arr.size() && arr[i] == 0)i++;

        while( i< arr.size()){
            ans+=arr[i]+'0';
            i++;
        }

    return ans;

    }
};