/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    int ans = 0;

private:
    bool isValid(vector<int>& hash) {
        // a arr can be psuedo palidromic if and only if there is one number whihc\
        is appearing odd times rest even time whihc makes a left - right pair
        // so hash it

        // now check for odd counts
        int odd = 0;
        for (int i = 1; i < 10; i++) {
            if (hash[i] != 0 && hash[i] % 2 != 0)
                odd++;

            if (odd > 1)
                return false;
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int>& hash) {
        // base case
        if (!root)
            return;

        // if we are at a leaf node we can check for psuedo-pallindrome
        if (!root->left && !root->right) {
            if (isValid(hash))
                ans++;

            return;
        }
        // go to left and right
        if (root->left) {
            hash[root->left->val]++;
            dfs(root->left, hash);
            hash[root->left->val]--;
        }
        if (root->right) {
            hash[root->right->val]++;
            dfs(root->right, hash);
            hash[root->right->val]--;
        }
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root)
            return 0;
        vector<int> hash(10, 0);
        hash[root->val]++;
        dfs(root, hash);
        return ans;
    }
};