/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    long long mini = LLONG_MAX;

    void helper(TreeNode* root, long long low, long long high) {
        if (!root) return;

        if (low != LLONG_MIN)
            mini = min(mini, (long long)root->val - low);

        if (high != LLONG_MAX)
            mini = min(mini, high - (long long)root->val);

        helper(root->left, low, root->val);
        helper(root->right, root->val, high);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        helper(root, LLONG_MIN, LLONG_MAX);
        return mini;
    }
};