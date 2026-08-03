class Solution {
private:
    bool isValid(string& s) {
        int opening = 0;

        for (int i = 0; i < s.size(); i++) {

            if (opening < 0)
                return false;
            if (s[i] == '(')
                opening++;
            else if (s[i] == ')')
                opening--;
        }
        return opening == 0;
    }
    vector<string> ans;

    void solve(int n, string& temp) {
        // if the size of temp reaches 2*n means we  have pair or n parentheisis
        if (temp.size() == 2 * n) {
            // we have to check for validity
            if (isValid(temp)) {
                ans.push_back(temp);
                return;
            }
            return;
        }

        // we are trying both the opening and closing for a current index
        temp.push_back('(');
        solve(n, temp);
        temp.pop_back();

        temp.push_back(')');
        solve(n, temp);
        temp.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {

        string temp = "";
        solve(n, temp);
        return ans;
    }
};