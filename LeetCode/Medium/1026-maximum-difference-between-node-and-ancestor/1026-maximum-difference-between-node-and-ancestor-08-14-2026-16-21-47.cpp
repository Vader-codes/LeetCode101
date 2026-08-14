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
    int maxDiff = 0;
    void dfs(TreeNode* root,int mini, int maxi){
        if(!root)return;
        maxDiff = max( maxDiff, max(abs(root->val - mini), abs(root->val - maxi)));

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        dfs(root->left, mini, maxi);
        dfs(root->right, mini, maxi);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        // just do a simple dfs but remember the path
        dfs(root, root->val, root->val);
         return maxDiff;           
    }
};