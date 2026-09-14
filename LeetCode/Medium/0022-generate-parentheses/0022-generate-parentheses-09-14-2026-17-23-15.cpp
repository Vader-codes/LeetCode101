class Solution {
private:
    vector<string> ans;

    void solve(int n, string& temp, int op, int cl) {
        // if the size of temp reaches 2*n means we  have pair or n parentheisis
        if (temp.size() == 2 * n) {
            // we have to check for validity

            ans.push_back(temp);
            return;
        }

        // we are trying both the opening and closing for a current index
        if (op < n) {
            temp.push_back('(');
            solve(n, temp, op + 1, cl);
            temp.pop_back();
        }
        if (cl < op) {
            temp.push_back(')');
            solve(n, temp, op, cl + 1);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        string temp = "";
        solve(n, temp, 0, 0);
        return ans;
    }
};