class Solution {
public:
    string addBinary(string a, string b) {

        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        bool carry = false;

        while (i >= 0 && j >= 0) {
            // there cases
            // first both are one
            if (a[i] == '1' && b[j] == '1') {
                if (carry)
                    ans += '1';

                else
                    ans += '0';

                carry = true;
            }
            // both are 0
            else if (a[i] == '0' && b[j] == '0') {
                if (carry) {

                    ans += '1';
                    carry = false;
                }

                else
                    ans += '0';

            }
            // one is  1 and other is 0
            else {
                if (carry) {
                    ans += '0';
                    carry = true;
                } else {
                    ans += '1';
                }
            }

            i--;
            j--;
        }

        // remaining digits of a
        while (i >= 0) {
            if (a[i] == '1') {
                if (carry) {
                    ans += '0';
                    carry = true;
                } else
                    ans += '1';
            } else {
                if (carry) {
                    ans += '1';
                    carry = false;
                } else {
                    ans += '0';
                }
            }
            i--;
        }

         // remaining digits of b
        while (j >= 0) {
            if (b[j] == '1') {
                if (carry) {
                    ans += '0';
                    carry = true;
                } else
                    ans += '1';
            } else {
                if (carry) {
                    ans += '1';
                    carry = false;
                } else {
                    ans += '0';
                }
            }
            j--;
        }

        if(carry) ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};